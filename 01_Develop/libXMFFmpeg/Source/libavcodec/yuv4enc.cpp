/*
 * libquicktime yuv4 encoder
 *
 * Copyright (c) 2011 Carl Eugen Hoyos
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "internal.h"

static av_cold int yuv4_encode_init(AVCodecContext *avctx)
{
    avctx->coded_frame = avcodec_alloc_frame();

    if (!avctx->coded_frame) {
        av_log(avctx, AV_LOG_ERROR, "Could not allocate frame.\n");
        return AVERROR(ENOMEM);
    }

    return 0;
}

static int yuv4_encode_frame(AVCodecContext *avctx, uint8_t *buf,
                             int buf_size, void *data)
{
    AVFrame *pic = (AVFrame *)data;
    uint8_t *dst = buf;
    uint8_t *y, *u, *v;
    int i, j;
    int output_size = 0;

    if (buf_size < 6 * (avctx->width + 1 >> 1) * (avctx->height + 1 >> 1)) {
        av_log(avctx, AV_LOG_ERROR, "Out buffer is too small.\n");
        return AVERROR(ENOMEM);
    }

    avctx->coded_frame->reference = 0;
    avctx->coded_frame->key_frame = 1;
    avctx->coded_frame->pict_type = AV_PICTURE_TYPE_I;

    y = pic->data[0];
    u = pic->data[1];
    v = pic->data[2];

    for (i = 0; i < avctx->height + 1 >> 1; i++) {
        for (j = 0; j < avctx->width + 1 >> 1; j++) {
            *dst++ = u[j] ^ 0x80;
            *dst++ = v[j] ^ 0x80;
            *dst++ = y[                   2 * j    ];
            *dst++ = y[                   2 * j + 1];
            *dst++ = y[pic->linesize[0] + 2 * j    ];
            *dst++ = y[pic->linesize[0] + 2 * j + 1];
            output_size += 6;
        }
        y += 2 * pic->linesize[0];
        u +=     pic->linesize[1];
        v +=     pic->linesize[2];
    }

    return output_size;
}

static av_cold int yuv4_encode_close(AVCodecContext *avctx)
{
    av_freep(&avctx->coded_frame);

    return 0;
}

static const enum PixelFormat _ff_yuv4_encoder[] = { PIX_FMT_YUV420P, PIX_FMT_NONE };
AVCodec ff_yuv4_encoder = {
    /*.name					= */	"yuv4",
    /*.type					= */	AVMEDIA_TYPE_VIDEO,
    /*.id					= */	CODEC_ID_YUV4,
    /*.priv_data_size		= */	0,
    /*.init					= */	yuv4_encode_init,
    /*.encode				= */	yuv4_encode_frame,
    /*.close				= */	yuv4_encode_close,
    /*.decode				= */	0,
    /*.capabilities			= */	0,
	/*.next					= */	0,
	/*.flush				= */	0,
	/*.supported_framerates	= */	0,
	/*.pix_fmts				= */	_ff_yuv4_encoder,
    /*.long_name			= */	NULL_IF_CONFIG_SMALL("Uncompressed packed 4:2:0"),
};

#ifndef EFFECTMANAGER_H_
#define EFFECTMANAGER_H_
#include "Base.h"

#include "3d/C3DVector2.h"
#include "3d/C3DVector3.h"
#include "3d/C3DVector4.h"
#include "3d/C3DMatrix.h"

#include <string>
#include <map>
#include "cocos2d.h"
#include "3d/C3DResourceManager.h"

namespace cocos3d
{

class C3DElementNode;
class C3DEffect;

/**
 *A C3DEffectManager manager effect's load��preload, and so on.
 */
class C3DEffectManager : public C3DResourceManager
{
public:	

	static C3DEffectManager* getInstance();
	
	virtual C3DResource* createResource(const std::string& name,C3DElementNode* node);

	/**
     * preload all shader files from the specific config file.
     *
     * @param fileName The path to the shader config file.     
     */
	virtual void preload(const std::string& fileName);
			
	 /**
     * get an effect using the specified vertex and fragment shader.
     * @return The created effect.
     */
	virtual C3DResource* getResource(const std::string& name);
	 /**
     * preload  this shader file.
     *
     * @param vshPath The path to the vertex shader file.
	 * @param fshPath The path to the fragment shader file.
	 * @param defines The precompile defines.
     */
	void preload(C3DElementNode* node);
		
	static std::string generateID( std::string& vshPath, std::string& fshPath, std::string& defines,C3DElementNode* outNode = NULL );
private:

    C3DEffectManager();

    ~C3DEffectManager();
	

	void loadAllEffect(C3DElementNode* effectNodes);	
   
};

}

#endif

/*
 * Copyright (c) 2012 Chukong Technologies, Inc.
 *
 * http://www.cocostudio.com
 * http://tools.cocoachina.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef COCOSTUDIO_CSARMATUREDATAMANAGER_H
#define COCOSTUDIO_CSARMATUREDATAMANAGER_H

#include "CSConstValue.h"
#include "CSDatas.h"
#include "CSArmature.h"


class TiXmlElement;

namespace cs {

/**
 *	@brief	format and manage armature configuration and armature animation
 */
class ArmatureDataManager : public cocos2d::CCObject 
{
public:
    static ArmatureDataManager *sharedArmatureDataManager();
private:
    ArmatureDataManager(void);
    ~ArmatureDataManager(void);

public:
	/**
     * Init ArmatureDataManager
     */
    virtual bool init();
    
    /**
     * Add armature data
     * @param id The id of the armature data
	 * @param armatureData ArmatureData *
     */
    void addArmatureData(const char *id, ArmatureData *armatureData);
    
	/**
     *	@brief	get armature data
     *
     *	@param	id the id of the armature data you want to get
	 *  
	 *  @return	ArmatureData *
     */
    ArmatureData *getArmatureData(const char *id);

    /**
     *	@brief	add animation data 
     *
     *	@param 	id the id of the animation data 
	 *
	 *  @return AnimationData *
     */
    void addAnimationData(const char *id, AnimationData *animationData);
    
	/**
     *	@brief	get animation data from m_pAnimationDatas(CCDictionary)
     *
     *	@param 	id the id of the animation data you want to get
	 *  
	 *  @return AnimationData *
     */
    AnimationData *getAnimationData(const char *id);

    /**
     *	@brief	add texture data 
     *
     *	@param 	id the id of the texture data
	 *
	 *  @return TextureData *
     */
    void addTextureData(const char *id, TextureData *textureData);
    
	/**
     *	@brief	get texture data
     *
     *	@param 	_id the id of the texture data you want to get
	 *  
	 *  @return TextureData *
     */
    TextureData *getTextureData(const char *id);
    
    /**
	 *	@brief	Add ArmatureFileInfo, it is managed by ArmatureDataManager.
     */
	void addArmatureFileInfo(const char *armatureName, const char *useExistFileInfo, const char *imagePath, const char *plistPath, const char *configFilePath);
    /**
	 *	@brief	Add ArmatureFileInfo, it is managed by ArmatureDataManager.
     */
	void addArmatureFileInfo(const char *imagePath, const char *plistPath, const char *configFilePath);

    /**
     *	@brief	Add sprite frame to CCSpriteFrameCache, it will save display name and it's relative image name
     */
    void addSpriteFrameFromFile(const char *plistPath, const char *imagePath);
    
	
	/**
	 *	@brief	Clear the data in the m_pArmarureDatas and m_pAnimationDatas, and set m_pArmarureDatas and m_pAnimationDatas to NULL
     */
    void removeAll();

   
private:
    /**
	 *	@brief	save amature datas
	 *  @key	std::string
	 *  @value	ArmatureData *
     */
	CC_SYNTHESIZE_READONLY(cocos2d::CCDictionary *, m_pArmarureDatas, ArmarureDatas);

    /**
	 *	@brief	save animation datas
	 *  @key	std::string
	 *  @value	AnimationData *
     */
	CC_SYNTHESIZE_READONLY(cocos2d::CCDictionary *, m_pAnimationDatas, AnimationDatas);

	/**
	 *	@brief	save texture datas
	 *  @key	std::string
	 *  @value	TextureData *
     */
	CC_SYNTHESIZE_READONLY(cocos2d::CCDictionary *, m_pTextureDatas, TextureDatas);

private:
    static ArmatureDataManager *m_sSharedArmatureDataManager;
};

}

#endif
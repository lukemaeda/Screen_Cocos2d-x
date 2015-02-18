//
//  SecondScene.h
//  Screen
//
//  Created by MAEDAHAJIME on 2015/02/18.
//
//

#ifndef __Screen__SecondScene__
#define __Screen__SecondScene__

#include "cocos2d.h"

USING_NS_CC;

class SecondScene : public cocos2d::Layer
{
public:
    static Scene *createScene();
    virtual bool init();
    CREATE_FUNC(SecondScene);
    
    void makeBackground();
    
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushBack(cocos2d::Ref *pSender);
};


#endif /* defined(__Screen__SecondScene__) */

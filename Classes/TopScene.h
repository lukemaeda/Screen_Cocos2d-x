//
//  TopScene.h
//  Screen
//
//  Created by MAEDAHAJIME on 2015/02/18.
//
//

#ifndef __Screen__TopScene__
#define __Screen__TopScene__

#include "cocos2d.h"

USING_NS_CC;

class TopScene : public cocos2d::Layer
{
public:
    static Scene *createScene();
    virtual bool init();
    CREATE_FUNC(TopScene);
    
    void makeBackground();
    
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushStart(Ref *pSender);
    
};

#endif /* defined(__Screen__TopScene__) */

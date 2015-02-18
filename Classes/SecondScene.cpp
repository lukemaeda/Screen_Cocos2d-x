//
//  SecondScene.cpp
//  Screen
//
//  Created by MAEDAHAJIME on 2015/02/18.
//
//

#include "SecondScene.h"
#include "TopScene.h"
//音をならすためにinclude
#include "SimpleAudioEngine.h"

Scene *SecondScene::createScene()
{
    auto scene = Scene::create();
    auto layer = SecondScene::create();
    scene->addChild(layer);
    return scene;
}

bool SecondScene::init()
{
    if (! Layer::init()) {
        return false;
    }
    
    // バックグラウンド
    makeBackground();
    
    //画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    
    //戻るボタンを設置
    auto backButton = MenuItemImage::create(
                                            "CloseNormalBack.png",  //表示
                                            "CloseSelected.png",  //タップ時の画像
                                            CC_CALLBACK_1(SecondScene::pushBack, this));
    
    backButton->setPosition(Point(winSize.width /2 ,winSize.height/2));
    
    //create menu, it's an autorelease object
    auto menu = Menu::create(backButton, NULL);
    
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu, 1);
    
    return true;
}

void SecondScene::makeBackground()
{
    //画面の座標関係の詳しい説明はここ
http://www.cocos2d-x.org/wiki/Coordinate_System
    //画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    //マルチレゾリューション対応がどうとか
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::ORANGE,
                                         winSize.width,
                                         winSize.height);
    //バックグランドカラー追加 第2引数は表示順
    this->addChild(background, 0);
    
    //タイトルを設置
    auto lbl_title = Label::createWithSystemFont
    ("Second", "HiraKakuProN-W6", 100);
    lbl_title->setPosition(Point(origin.x + winSize.width/2,
                                 origin.y + winSize.height
                                 -lbl_title->getContentSize().height));
    this->addChild(lbl_title,1);
}

// pushBackボタン
void SecondScene::pushBack(Ref *pSender)
{
    // 効果音を鳴らす
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
    
    // 遷移先の画面のインスタンス
    Scene *pScene = TopScene::createScene();
    
    // 0.5秒かけてフェードアウトしながら次の画面に遷移します
    //    引数１:フィードの時間
    //    引数２：移動先のシーン
    //    引数３：フィードの色（オプション）
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    //遷移実行  遷移時のアニメーション
    Director::getInstance()->replaceScene(transition);
}
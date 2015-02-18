//
//  TopScene.cpp
//  Screen
//
//  Created by MAEDAHAJIME on 2015/02/18.
//
//

#include "TopScene.h"
#include "SecondScene.h"
//音をならすためにinclude
#include "SimpleAudioEngine.h"

Scene *TopScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TopScene::create();
    scene->addChild(layer);
    return scene;
}

bool TopScene::init()
{
    if (! Layer::init()) {
        return false;
    }
    
    // バックグラウンド
    makeBackground();
    
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getWinSize();
    
    // スタートボタンを設置
    auto startButton = MenuItemImage::create(
                                             "CloseNormalGo.png",  // 通常状態の画像
                                             "CloseSelected.png",  // 押下状態の画像
                                             CC_CALLBACK_1(TopScene::pushStart, this)); // 押下時のアクション
    // ボタンの設置
    startButton->setPosition(Point(winSize.width /2 ,winSize.height/2));
    
    // メニューを作成 自動解放オブジェクト
    auto menu = Menu::create(startButton, NULL);
    //
    menu->setPosition(Point::ZERO);
    // メニューを追加
    this->addChild(menu, 1);
    
    return true;
}

void TopScene::makeBackground()
{
    
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getWinSize();
    //マルチレゾリューション対応がどうとか
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    // バックグランドカラー 第2引数は表示順
    this->addChild(background, 0);
    
    // タイトルを設置
    auto lbl_title = Label::createWithSystemFont
    ("Top","HiraKakuProN-W6", 100);
    lbl_title->setPosition(Point(origin.x + winSize.width/2,
                                 origin.y + winSize.height
                                 -lbl_title->getContentSize().height));
    // ラベルタイトルを追加
    this->addChild(lbl_title,1);
}

//
void TopScene::pushStart(Ref *pSender)
{
    CCLOG("Pushボタン");
    
    // 効果音を鳴らす
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
    
    // 遷移先の画面のインスタンス
    Scene *pScene = SecondScene::createScene();
    
    // 0.5秒かけてフェードアウトしながら次の画面に遷移します
    //    引数１:フィードの時間
    //    引数２：移動先のシーン
    //    引数３：フィードの色（オプション）
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    // 遷移実行  遷移時のアニメーション
    // 直前のsceneはもう使わないから捨ててしまう方法。基本はこれになります。
    Director::getInstance()->replaceScene(transition);
}
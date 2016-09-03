//
//  Constants.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/02.
//
//

#ifndef Constants_hpp
#define Constants_hpp

//=========================================================================
// 関数やマクロ定義はここから
//=========================================================================
/**
 *  @desc   引数の正負ゼロを返す
 *  @param  数値
 *  @return 1...正 -1...負 0...ゼロ
 */
template <typename Num>
static int getSign(Num number){
    Num sign = (number > 0) - (number < 0) ;
    return (int)sign ;
}

//=========================================================================
//	CCREATE_FUNC
//      CREATE_FUNCマクロの汎用化静的メンバ関数テンプレート群
//=========================================================================
class CCREATE_FUNC {
public :
    /**
     *  @desc   通常の生成
     */
    template <typename Ty>
    static Ty* create() {
        Ty* pRet = new(std::nothrow)Ty() ;
        if(pRet && pRet->init()) {
            pRet->autorelease() ;
            return pRet ;
        }else{
            delete pRet ;
            pRet = NULL ;
            return NULL ;
        }
    }
    
};

//=========================================================================
//
// ランダム数値生成クラス
//
//=========================================================================
class RANDOM_FUNC {
public :
    /**
     *  @desc   ランダムな数値を返す関数
     *  @param  ランダム範囲の開始数値
     *  @param  ランダム範囲の終了数値
     *  @rerurn ランダム数値
     */
    static int random(int start, int end){
        // ランダム添字番号生成器
        std::random_device rnd ;
        std::mt19937 mt(rnd()) ;
        // ランダム値の範囲を、参照元配列の要素数範囲に設定する
        std::uniform_int_distribution<> rand(start, end);
        
        // ランダムに１つ参照元配列の中から添字番号を選ぶ
        return rand(mt) ;
    }
};


//=========================================================================
// 画面サイズ
//=========================================================================
#define WINDOW_WIDTH    (900)
#define WINDOW_HEIGHT   (600)

//=========================================================================
//	画像ファイルのマクロはここから書く
//=========================================================================

#endif /* Constants_hpp */

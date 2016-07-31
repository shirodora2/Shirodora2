//
//  AggregateTemplate.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/18.
//
//

#ifndef AggregateTemplate_hpp
#define AggregateTemplate_hpp

//=========================================================================
// 前方宣言
//=========================================================================
template<typename Ty>
class CIteratorTemplate ;

//=========================================================================
//
// AggregateTemplate
//
//=========================================================================
template<typename Ty>
class IAggregateTemplate {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   デストラクタ
     */
    virtual ~IAggregateTemplate(){}
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   最大サイズの取得
     *  @return サイズ
     */
    virtual int getSize() = 0 ;
    
    /**
     *  @desc   要素の中身の取得
     *  @param  要素の中身
     */
    virtual Ty getAt(int) = 0 ;
    
    /**
     *  @desc   開始イテレーターの取得
     *  @return
     */
    virtual std::shared_ptr<CIteratorTemplate<Ty>> iterator() = 0 ;
    
};

//=========================================================================
//
// IteratorTemplate
//
//=========================================================================
template<typename Ty>
class CIteratorTemplate {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CIteratorTemplate(IAggregateTemplate<Ty> *pAggre) : m_pAggre(pAggre){}
    
    /**
     *  @desc   デストラクタ
     */
    virtual ~CIteratorTemplate(){}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   次が存在するかどうかをチェック
     *  @return true...次がある false...次がない
     */
    inline virtual bool hasNext(){
        if(m_pAggre->getSize() <= this->m_currentIndex) return false ;
        return true ;
    }
    
    /**
     *  @desc   現在の添え字番号の中身を返し、添え字番号をインクリメントする
     *  @return 現在の添え字番号の中身
     */
    inline Ty next(){
        // 現在の要素の中身を取得
        Ty item = this->m_pAggre->getAt(this->m_currentIndex) ;
        // 添え字番号を次にする
        ++this->m_currentIndex ;
        // 要素の中身を returnする
        return item ;
    }
    
protected :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 繰り返しを行う集合体の参照
    IAggregateTemplate<Ty> *m_pAggre {NULL} ;
    
    // 現在の添え字番号
    int m_currentIndex = 0 ;
    
};

#endif /* AggregateTemplate_hpp */

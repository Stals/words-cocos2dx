#include "word.h"

USING_NS_CC;

//TODO в терии € могу от меню наследоватьс€, хот€ хз коненчо
// TODO align должен сам их по ширине делать праивльно!
Word::Word(std::string word){
	CCLayer::init();
	this->autorelease();

	for(int id = 0; id < word.size(); ++id){
		Letter *letter = new Letter(word[id], id);
		this->addChild(letter);
		//letters.push_back(letter);
	}
}
// ћне либо нужно уметь правильно отрисовывать, либо добавить в себ€ и просто в правильное место зафигачить

Word::~Word(void)
{
}

void Word::alignLettersHorizontallyWithPadding(float padding){
    float width = -padding;
    if (m_pChildren && m_pChildren->count() > 0)
    {
        CCObject* pObject = NULL;
        CCARRAY_FOREACH(m_pChildren, pObject)
        {
            CCNode* pChild = dynamic_cast<CCNode*>(pObject);
            if (pChild)
            {
                width += pChild->getContentSize().width * pChild->getScaleX() + padding;
            }
        }
    }

    float x = -width / 2.0f;
    if (m_pChildren && m_pChildren->count() > 0)
    {
        CCObject* pObject = NULL;
        CCARRAY_FOREACH(m_pChildren, pObject)
        {
            CCNode* pChild = dynamic_cast<CCNode*>(pObject);
            if (pChild)
            {
                pChild->setPosition(ccp(x + pChild->getContentSize().width * pChild->getScaleX() / 2.0f, 0));
                 x += pChild->getContentSize().width * pChild->getScaleX() + padding;
            }
        }
    }
}


void Word::randomlyRotateLetters(){
	// на сколько градусов в каждую сотрону можно развенрнуть букву
	const int range = 10;
	if (m_pChildren && m_pChildren->count() > 0)
    {
        CCObject* pObject = NULL;
        CCARRAY_FOREACH(m_pChildren, pObject)
        {
            CCNode* pChild = dynamic_cast<CCNode*>(pObject);
            if (pChild)
            {
				int r = rand() % (range * 2);
				pChild->runAction(CCRotateBy::create(0, r - range));
			}
		}
	}

}
#include "word.h"

USING_NS_CC;

Word::Word(){
	CCLayer::init();
	this->setTouchEnabled(true);
	this->autorelease();
}

//TODO в терии € могу от меню наследоватьс€, хот€ хз коненчо
// TODO align должен сам их по ширине делать праивльно!
Word::Word(std::string word){
	CCLayer::init();
	this->setTouchEnabled(true);
	this->autorelease();

	initWithString(word);
}
// ћне либо нужно уметь правильно отрисовывать, либо добавить в себ€ и просто в правильное место зафигачить

Word::~Word(void)
{
}

// TODO - в теории нужно будет еще все сбрасывать как-то
void Word::initWithString(std::string word){
	for(size_t id = 0; id < word.size(); ++id){
		appendLetter(word[id]);
		//Letter *letter = new Letter(word[id], id);
		//this->addChild(letter, 0, id);
		//letters.push_back(letter);
	}
}

void Word::appendLetter(char l){
	int id = this->getChildrenCount();
	Letter *letter = new Letter(l, id);
	this->addChild(letter, 0, id);
}

void Word::appendLetter(Letter *letter){
	int id = this->getChildrenCount();
	Letter *l = new Letter(letter->letter, letter->id);
	this->addChild(l, 0, id);
}

void Word::removeLetter(size_t id){
	this->removeChildByTag(id, true);
}

Letter* Word::getLetter(size_t id){
	Letter* letter = dynamic_cast<Letter*>(this->getChildByTag(id));
	return letter;
}

void Word::showLetter(size_t id){
	this->getChildByTag(id)->setVisible(true);
}

void Word::hideLetter(size_t id){
	this->getChildByTag(id)->setVisible(false);
}


std::string Word::getString(){
	std::string result = "";
	if (m_pChildren && m_pChildren->count() > 0)
    {
        CCObject* pObject = NULL;
        CCARRAY_FOREACH(m_pChildren, pObject)
        {
			Letter* pChild = dynamic_cast<Letter*>(pObject);
			result += pChild->letter;
		}
	}
	return result;
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




bool Word::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event){
	return true;
}

void Word::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event){

}

void Word::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event){

}

void Word::registerWithTouchDispatcher(){
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false); // false
}

void Word::addContainedWord(std::string word){
	contains.insert(word);
}

bool Word::isContained(std::string word){
	if(contains.find(word) != contains.end())
		return true;
	return false;
}


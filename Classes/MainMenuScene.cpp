#include "MainMenuScene.h"
#include "ui/CocosGUI.h"
cocos2d::Scene * MainMenuScene::createScene()
{
	return MainMenuScene::create();
}

bool MainMenuScene::init()
{
	const int MENU_ITEM_FONT_SIZE = 56;
	auto dirs = Director::getInstance();
	Size visibleSize = dirs->getVisibleSize();

	play_label = Label::createWithTTF(u8"������", "fonts/arial.ttf", MENU_ITEM_FONT_SIZE); //�������� ������� (Label)
	menu_play_label = MenuItemLabel::create(play_label, CC_CALLBACK_1(MainMenuScene::menu_play_onClick, this)); //�������� "�������� ����" �� �������

	options_label = Label::createWithTTF(u8"���������", "fonts/arial.ttf", MENU_ITEM_FONT_SIZE);
	menu_options_label = MenuItemLabel::create(options_label);

	exit_label = Label::createWithTTF(u8"�����", "fonts/arial.ttf", MENU_ITEM_FONT_SIZE);
	menu_exit_label = MenuItemLabel::create(exit_label, CC_CALLBACK_1(MainMenuScene::menu_exit_onClick, this));
	
	
	menu = Menu::create(menu_play_label, menu_options_label, menu_exit_label, nullptr); //�������� ���� �� "�������� ����"
	menu->alignItemsVerticallyWithPadding(30); // ������������ ������������ ��������� � �������� � 30 ��������
	//menu->alignItemsHorizontallyWithPadding(15);
	this->addChild(menu, 1);
	
	
	
	



	return true;
}

void MainMenuScene::menu_exit_onClick(Ref * sender)
{
	auto director = Director::getInstance(); 
	director->end(); //���������� ������ ��������� � ����� ��� �� ��������
}

void MainMenuScene::menu_play_onClick(Ref * sender)
{
	auto director = Director::getInstance();
	director->pushScene(this);
	auto game = HelloWorld::create();
	director->replaceScene(game);

}



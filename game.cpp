#include "game.h"


Game::Game(QWidget *parent):QGraphicsView(parent)
{
    //making the window
    setFixedSize(1400,880);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

   //make the game
    gameScene = new QGraphicsScene(this);
    gameScene->setSceneRect(0,0,1400,880);
    QGraphicsPixmapItem *bg = new QGraphicsPixmapItem();
    bg->setPixmap(QPixmap(":/images/images/bg.jpg").scaled(1400,880));
    gameScene->addItem(bg);

    setScene(gameScene);
    score = new Score();
    gameScene->addItem(score);
    snake2 = NULL;
    snake = NULL;

}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(snake)
    snake->keyPressEvent(event);
    else
        QGraphicsView::keyPressEvent(event);
}

void Game::displayMainMenu(QString title,QString play)
{
   //create the title
    titleText = new QGraphicsTextItem(title);
    QFont titleFont("arial" , 50);
    titleText->setFont( titleFont);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    gameScene->addItem(titleText);

  //create the button
  //play
    Button * playButton = new Button(play,titleText);
    int pxPos = 160 ;
    int pyPos = 160;
    playButton->setPos(pxPos,pyPos);

    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
//exit
    Button * quitButton = new Button("Exit",titleText);
    int qxPos = 160;
    int qyPos = 230;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));


}
void Game::start(){
    snake = new MoveSnake();
    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();
    score->setVisible(true);
    score->setScore(0);
    gameScene->addItem(snake);
    gameScene->removeItem(titleText);
    delete titleText;
    if (snake2)
    snake2->deleteLater();
    snake2 = snake;
}

void Game::gameOver(){
    displayMainMenu("Game Over!","Play Again");
    gameScene->removeItem(snake);
//remove snake;
}


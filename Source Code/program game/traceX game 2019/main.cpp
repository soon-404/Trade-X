#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "random.h"
#include "Projectile.h"
#include "Collision.h"

using namespace std;

int main()
{
	bool enterG = false;
	bool enterO = false;
	bool enterD = false;
	//valuable	
	char last_char = ' ';
	int getBullet;
	int enterTime1;
	int enterTime2;
	int enterTime3;
	int posxh, posyh;
	int coinpx, coinpy;
	int bronzeCoinpx, bronzeCoinpy;
	int silverCoinpx, silverCoinpy;
	int goldCoinpx, goldCoinpy;
	int gunpx, gunpy;
	int aidpx, aidpy;
	int timerMonster;
	int timerShooter;
	int timerLavar;
	int timerBoss;
	int timeBossDead;
	int restarttimelevel0      =  1;
	int restarttimelevel1      =  1;
	int restarttimelevel2      =  1;
	int restarttimelevel3      =  1;
	int monsterSpawnTime       =  5;
	int shooterSpawnTime       =  5;
	int lavarSpawnTime         =  5;
	int level                  =  0;
	int score                  =  0;
	int counter                =  0;
	int counter2               =  0;
	int counter3               =  0;
	int counter4               =  0;
	int counterShooter         =  0;
	int counterLavar           =  0;
	int counterBoss            =  0;
	int counterM               =  0;
	int counterMB              =  0;
	int counterS               =  0;
	int counterSB              =  0;
	int counterL               =  0;
	int counterLB              =  0;
	int counterP               =  0;
	int counterWalkingMonster  =  0;
	int counterWalkingShooter  =  0;
	int counterWalkingLavar    =  0;
	int counterWalkingBoss     =  0;
	int counterMenu            =  1;
	int counterSetting         =  1;
	int counterExtra           =  1;
	int keyspace               =  0;
	int keyC                   =  0;
	int enterShield            =  0;
	int enterCoin              =  0;
	int enterBronzeCoin        =  0;
	int enterSilverCoin        =  0;
	int enterGoldCoin          =  0;
	int enterGun               =  0;
	int enterAid               =  0;
	int gtime1                 =  0;
	int gtime2                 =  0;
	int gtime3                 =  0;
	int remm                   =  1;
	int ctime1                 =  0;
	int ctime2                 =  0;
	int ctime3                 =  0;
	char bufferScore[500];
	char bufferTimeLevel1[500];
	char bufferTimeLevel2[500];
	char bufferTimeLevel3[500];
	char bufferHealth[500];
	char scoree[500];
	bool startButton           =  false;
	bool scoreButton           =  false;
	bool settingButton         =  false;
	bool extraButton           =  false;
	bool exitButton            =  false;
	bool confirmYesButton      =  false;
	bool confirmNoButton       =  false;
	bool soundOnButton         =  false;
	bool soundOffButton        =  false;
	bool keyDown               =  false;
	bool keyUp                 =  false;
	bool keyLeft               =  false;
	bool keyRight              =  false;
	bool enterAttack           =  false;
	bool loadingScene          =  false;
	bool loadingScene2         =  false;
	bool loadingScene3         = false;
	bool restartTimeLoadingScene = true;
	bool restartTimeLoadingScene2 = true;
	bool restartTimeLoadingScene3 = true;
	bool confirmExit           =  false;
	bool confirmExitState      =  false;
	bool drawPlayerBeforeEnemy =  false;
	bool enterMonsterTurn      =  false;
	bool powerBullet           =  false;
	bool lose                  =  false;
	bool endgame               =  true;
	bool state                 =  false;
	bool saveScore             =  false;
	bool showScore             =  false;
	bool pause                 =  false;
	bool play                  =  false;
	bool enterTimeLevel1       =  true;
	bool enterTimeLevel2       =  true;
	bool enterTimeLevel3       =  true;
	bool goExit                =  false;
	bool formLevel1            =  false;
	bool formLevel2            =  false;
	bool formLevel3            =  false;
	bool soundGameOver         =  false;
	bool soundGameVictory      =  false;
	bool tutorial              =  false;
	bool howtoplay             =  false;
	bool collect               =  false;
	bool mission               =  false;

	string alltime;
	string input;
	float timerLoadingScene;
	float timerLoadingScene2;
	float timerLoadingScene3;
	float playerattackswordtime;
	float deltatimeplayerattacksword;
	float timerlevel1           =  0;
	float timerlevel1milli      =  0;
	float timerlevel2           =  0;
	float timerlevel2milli      =  0;
	float timerlevel3           =  0;
	float timerlevel3milli      =  0;
	float totalTime             =  0;
	unsigned long long int nowtimelevel1;
	unsigned long long int aftercounttimelevel1;
	unsigned long long int nowtimelevel2;
	unsigned long long int aftercounttimelevel2;
	unsigned long long int nowtimelevel3;
	unsigned long long int aftercounttimelevel3;
	srand(time(NULL));
	fstream myFile;
	fstream myFile2;

	//----------------------------------------------------------------------------------------------------------------------------------------------------------
	
	
	//Create Window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "TraceX", sf::Style::Fullscreen);

	//No Mouse
	window.setMouseCursorVisible(false);

	//Framerate
	window.setFramerateLimit(60);

	//View
	sf::View view1(sf::FloatRect(200, 200, 300, 200));
	view1.setSize(sf::Vector2f(1280, 720));
	view1.setCenter(sf::Vector2f(view1.getSize().x / 2, view1.getSize().y / 2));

    //---------------------------------------------------------------------------------------------------------------------------------------------------------


	//Clock
	sf::Clock clock;


	//---------------------------------------------------------------------------------------------------------------------------------------------------------
	
	
	//font
	sf::Font font;
	if (!font.loadFromFile("font/PressStart2P.ttf"))
	{
		return EXIT_FAILURE; 
	}

	//text "Start"
	sf::Text textStart;
	textStart.setFont(font);
	textStart.setString("Start");
	textStart.setCharacterSize(35); 
	textStart.setFillColor(sf::Color::White);
	textStart.setPosition(300, 400);
	textStart.setStyle(sf::Text::Bold | sf::Text::Underlined);


	//text "Score"
	sf::Text textScore;
	textScore.setFont(font);
	textScore.setString("Score");
	textScore.setCharacterSize(35);
	textScore.setFillColor(sf::Color::White);
	textScore.setPosition(300, 500);


	//text "Setting"
	sf::Text textSetting;
	textSetting.setFont(font);
	textSetting.setString("Setting");
	textSetting.setCharacterSize(35);
	textSetting.setFillColor(sf::Color::White);
	textSetting.setPosition(300, 600);


	//text "Extra"
	sf::Text textExtra;
	textExtra.setFont(font);
	textExtra.setString("Extra");
	textExtra.setCharacterSize(35);
	textExtra.setFillColor(sf::Color::White);
	textExtra.setPosition(300, 700);


	//text "Exit"
	sf::Text textExit;
	textExit.setFont(font);
	textExit.setString("Exit");
	textExit.setCharacterSize(35);
	textExit.setFillColor(sf::Color::White);
	textExit.setPosition(300, 800);

	//text "On"
	sf::Text textSoundOn;
	textSoundOn.setFont(font);
	textSoundOn.setString("On");
	textSoundOn.setCharacterSize(35);
	textSoundOn.setFillColor(sf::Color::White);
	textSoundOn.setPosition(600, 600);

	//text "Off"
	sf::Text textSoundOff;
	textSoundOff.setFont(font);
	textSoundOff.setString("Off");
	textSoundOff.setCharacterSize(35);
	textSoundOff.setFillColor(sf::Color::White);
	textSoundOff.setPosition(1200, 600);

	//text score line 1
	sf::Text textScoreLine1;
	textScoreLine1.setFont(font);
	textScoreLine1.setCharacterSize(35);
	textScoreLine1.setFillColor(sf::Color::White);

	//text score line 2
	sf::Text textScoreLine2;
	textScoreLine2.setFont(font);
	textScoreLine2.setCharacterSize(35);
	textScoreLine2.setFillColor(sf::Color::White);

	//text score line 3
	sf::Text textScoreLine3;
	textScoreLine3.setFont(font);
	textScoreLine3.setCharacterSize(35);
	textScoreLine3.setFillColor(sf::Color::White);

	//text score line 4
	sf::Text textScoreLine4;
	textScoreLine4.setFont(font);
	textScoreLine4.setCharacterSize(35);
	textScoreLine4.setFillColor(sf::Color::White);

	//text score line 5
	sf::Text textScoreLine5;
	textScoreLine5.setFont(font);
	textScoreLine5.setCharacterSize(35);
	textScoreLine5.setFillColor(sf::Color::White);

	//text name line 1
	sf::Text textNameLine1;
	textNameLine1.setFont(font);
	textNameLine1.setCharacterSize(35);
	textNameLine1.setFillColor(sf::Color::White);

	//text name line 2
	sf::Text textNameLine2;
	textNameLine2.setFont(font);
	textNameLine2.setCharacterSize(35);
	textNameLine2.setFillColor(sf::Color::White);

	//text name line 3
	sf::Text textNameLine3;
	textNameLine3.setFont(font);
	textNameLine3.setCharacterSize(35);
	textNameLine3.setFillColor(sf::Color::White);
	
	//text name line 4
	sf::Text textNameLine4;
	textNameLine4.setFont(font);
	textNameLine4.setCharacterSize(35);
	textNameLine4.setFillColor(sf::Color::White);

	//text name line 5
	sf::Text textNameLine5;
	textNameLine5.setFont(font);
	textNameLine5.setCharacterSize(35);
	textNameLine5.setFillColor(sf::Color::White);

	// tect "score"
	sf::Text textscore;
	textscore.setFont(font);
	textscore.setCharacterSize(20);
	textscore.setFillColor(sf::Color::Black);

	// text "point"
	sf::Text textpoint;
	textpoint.setFont(font);
	textpoint.setCharacterSize(20);
	textpoint.setFillColor(sf::Color::Black);

	// text "TimeLevel1"
	sf::Text textTimeLevel1;
	textTimeLevel1.setFont(font);
	textTimeLevel1.setCharacterSize(20);
	textTimeLevel1.setFillColor(sf::Color::Black);
	
	// text "TimeLevel2"
	sf::Text textTimeLevel2;
	textTimeLevel2.setFont(font);
	textTimeLevel2.setCharacterSize(20);
	textTimeLevel2.setFillColor(sf::Color::Black);

	// text "TimeLevel3"
	sf::Text textTimeLevel3;
	textTimeLevel3.setFont(font);
	textTimeLevel3.setCharacterSize(20);
	textTimeLevel3.setFillColor(sf::Color::Black);


	// text "Health"
	sf::Text textHealth;
    textHealth.setFont(font);
	textHealth.setCharacterSize(20);
	textHealth.setFillColor(sf::Color::Black);


	// text "Boss"
	sf::Text textBoss;
	textBoss.setFont(font);
	textBoss.setCharacterSize(20);
	textBoss.setFillColor(sf::Color::Black);
	textBoss.setString("Boss");

	// text name input
	sf::Text textName;
	textName.setFont(font);
	textName.setCharacterSize(40);
	textName.setFillColor(sf::Color::Black);
	textName.setPosition(730, 1080/2-20);

	// text score output
	sf::Text textPoint;
	textPoint.setFont(font);
	textPoint.setCharacterSize(40);
	textPoint.setFillColor(sf::Color::White);
	textPoint.setPosition(1920/2-150 , 1080 /2 - 130);

	// text creator name
	sf::Text textMyName;
	textMyName.setFont(font);
	textMyName.setCharacterSize(30);
	textMyName.setFillColor(sf::Color::Black);
	textMyName.setString("62010336 Thanakorn Chancherngpanich");
	textMyName.setPosition(420,1030);


	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// shape name
	sf::RectangleShape cursor;
	cursor.setSize(sf::Vector2f(5, 64));
	cursor.setPosition((1920 / 2) - 240, 1080 / 2);
	cursor.setOrigin(2.5, 32);
	cursor.setFillColor(sf::Color::Blue);
	

	//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	//Main Menu Background
	sf::Texture textureBackgroundMenu;
	if (!textureBackgroundMenu.loadFromFile("image/info.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteBackgroundMenu(textureBackgroundMenu);

	//Loading Scene Level 1
	sf::Texture textureLoadingSceneLevel1;
	if (!textureLoadingSceneLevel1.loadFromFile("image/level1loading.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLoadingSceneLevel1(textureLoadingSceneLevel1);

	//Level 1 Background
	sf::Texture textureLevel1Background;
	if (!textureLevel1Background.loadFromFile("image/level1bg.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLevel1Background(textureLevel1Background);

	//Level 1 Behide Background
	sf::Texture textureLevel1BehideBackground;
	if (!textureLevel1BehideBackground.loadFromFile("image/bh1.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLevel1BehideBackground(textureLevel1BehideBackground);
	spriteLevel1BehideBackground.setPosition(-1200, -1200);

	//Loading Scene Level 2
	sf::Texture textureLoadingSceneLevel2;
	if (!textureLoadingSceneLevel2.loadFromFile("image/level2loading.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLoadingSceneLevel2(textureLoadingSceneLevel2);

	//Level 2 Background
	sf::Texture textureLevel2Background;
	if (!textureLevel2Background.loadFromFile("image/level2bg.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLevel2Background(textureLevel2Background);

	//Level 2 Behide Background
	sf::Texture textureLevel2BehideBackground;
	if (!textureLevel2BehideBackground.loadFromFile("image/bh2.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLevel2BehideBackground(textureLevel2BehideBackground);
	spriteLevel2BehideBackground.setPosition(-1200, -1200);

	//Loading Scene Level 3
	sf::Texture textureLoadingSceneLevel3;
	if (!textureLoadingSceneLevel3.loadFromFile("image/level3loading.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLoadingSceneLevel3(textureLoadingSceneLevel3);

	//Level 3 Background
	sf::Texture textureLevel3Background;
	if (!textureLevel3Background.loadFromFile("image/level3bg.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLevel3Background(textureLevel3Background);

	//Level 3 Behide Background
	sf::Texture textureLevel3BehideBackground;
	if (!textureLevel3BehideBackground.loadFromFile("image/bh3.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLevel3BehideBackground(textureLevel3BehideBackground);
	spriteLevel3BehideBackground.setPosition(-1200, -1200);
	
	//Lose Background
	sf::Texture textureLose;
	if (!textureLose.loadFromFile("image/lose.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLose(textureLose);

	//Win Background
	sf::Texture textureWin;
	if (!textureWin.loadFromFile("image/win.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteWin(textureWin);

	//Pause Background
	sf::Texture texturePause;
	if (!texturePause.loadFromFile("image/pause.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spritePause(texturePause);

	//Score Background
	sf::Texture textureScore;
	if (!textureScore.loadFromFile("image/score.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteScore(textureScore);

	//Setting Background
	sf::Texture textureSetting;
	if (!textureSetting.loadFromFile("image/setting.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteSetting(textureSetting);

	//Control Background
	sf::Texture textureControl;
	if (!textureControl.loadFromFile("image/control.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteControl(textureControl);

	//Mission Background
	sf::Texture textureMission;
	if (!textureMission.loadFromFile("image/mission.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteMission(textureMission);

	//Collect Background
	sf::Texture textureCollect;
	if (!textureCollect.loadFromFile("image/collectitem.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteCollect(textureCollect);

	//Howtoplay Background
	sf::Texture textureHowtoplay;
	if (!textureHowtoplay.loadFromFile("image/howtoplay.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteHowtoplay(textureHowtoplay);

	//Extra Character
	sf::Texture textureCharacter;
	if (!textureCharacter.loadFromFile("image/character.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteCharacter(textureCharacter);

	//Extra Item
	sf::Texture textureItem;
	if (!textureItem.loadFromFile("image/item.jpg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteItem(textureItem);

	//HPr Sprite
	sf::Texture textureHPr;
	if (!textureHPr.loadFromFile("image/HPr.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteHPr(textureHPr);
	spriteHPr.setScale(4,2 );
	//spriteHPr.setPosition(1650, 40);

	//HPb Sprite
	sf::Texture textureHPb;
	if (!textureHPb.loadFromFile("image/HPb.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteHPb(textureHPb);
	spriteHPb.setScale(4, 2);
	//spriteHPb.setPosition(1650, 40);

	//HPmr Sprite
	sf::Texture textureHPmr;
	if (!textureHPmr.loadFromFile("image/HPmr.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteHPmr(textureHPmr);

	//HPmb Sprite
	sf::Texture textureHPmb;
	if (!textureHPmb.loadFromFile("image/HPmb.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteHPmb(textureHPmb);



	//Normal Player Sprite
	sf::Texture texturePlayer;
	if (!texturePlayer.loadFromFile("image/Warrior.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spritePlayer(texturePlayer);
	spritePlayer.setTextureRect(sf::IntRect(0, 0, 128, 128));
	spritePlayer.setPosition(920, 540);


	//Monster Sprite
	sf::Texture textureMonster;
	if (!textureMonster.loadFromFile("image/Monsters.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteMonster(textureMonster);
	spriteMonster.setTextureRect(sf::IntRect(0, 0, 96, 96));
	spriteMonster.setPosition(100, 300);
	sf::RectangleShape rectangle(sf::Vector2f(96, 96));
	rectangle.setPosition(100, 300);

	//Shooter Sprite
	sf::Texture textureShooter;
	if (!textureShooter.loadFromFile("image/Shooter.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteShooter(textureShooter);
	spriteShooter.setTextureRect(sf::IntRect(0, 0, 96, 96));
	spriteShooter.setPosition(100, 300);
	sf::RectangleShape rectangle2(sf::Vector2f(96, 96));
	rectangle2.setPosition(300, 100);

	//Lavar Sprite
	sf::Texture textureLavar;
	if (!textureLavar.loadFromFile("image/Lavar.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLavar(textureLavar);
	spriteLavar.setTextureRect(sf::IntRect(0, 0, 96, 96));
	spriteLavar.setPosition(100, 300);
	sf::RectangleShape rectangle3(sf::Vector2f(96, 96));
	rectangle3.setPosition(300, 100);

	//Boss Sprite
	sf::Texture textureBoss;
	if (!textureBoss.loadFromFile("image/boss.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteBoss(textureBoss);
	spriteBoss.setTextureRect(sf::IntRect(0, 0, 160, 160));
	spriteBoss.setPosition(100, 300);
	sf::RectangleShape rectangle4(sf::Vector2f(260, 260));
	rectangle4.setPosition(700, 700);

	//Bullet Sprite
	sf::Texture textureBullet;
	if (!textureBullet.loadFromFile("image/bullet.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteBullet(textureBullet);
	spriteBullet.setTextureRect(sf::IntRect(0, 0, 0, 0));

	//Shoulder Cannon Sprite
	sf::Texture textureShoulderCannon;
	if (!textureShoulderCannon.loadFromFile("image/shoulderCannon.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteShoulderCannon(textureShoulderCannon);
	spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 128, 128));

	//Gold Coin Sprite
	sf::Texture textureGoldCoin;
	if (!textureGoldCoin.loadFromFile("image/gold coin.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteGoldCoin(textureGoldCoin);
	spriteGoldCoin.setTextureRect(sf::IntRect(0, 0, 64, 64));

	//Silver Coin Sprite
	sf::Texture textureSilverCoin;
	if (!textureSilverCoin.loadFromFile("image/silver coin.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteSilverCoin(textureSilverCoin);
	spriteSilverCoin.setTextureRect(sf::IntRect(0, 0, 64, 64));

	//Bronze Coin Sprite
	sf::Texture textureBronzeCoin;
	if (!textureBronzeCoin.loadFromFile("image/bronze coin.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteBronzeCoin(textureBronzeCoin);
	spriteBronzeCoin.setTextureRect(sf::IntRect(0, 0, 96, 96));

	//Aid Sprite
	sf::Texture textureAid;
	if (!textureAid.loadFromFile("image/aid.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteAid(textureAid);
	spriteAid.setTextureRect(sf::IntRect(0, 0, 64, 64));

	//Gun Sprite
	sf::Texture textureGun;
	if (!textureGun.loadFromFile("image/gun.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteGun(textureGun);
	spriteGun.setTextureRect(sf::IntRect(0, 0, 64, 64));

	//Plasma Sprite
	sf::Texture texturePlasma;
	if (!texturePlasma.loadFromFile("image/plasma.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spritePlasma(texturePlasma);
	spritePlasma.setTextureRect(sf::IntRect(0, 0, 64, 64));


	//-------------------------------------------------------------------------------------------------------------------------------------------
	
	
	// Main Menu sound
	sf::Music musicMenu;
	if (!musicMenu.openFromFile("sound/menuOST.ogg"))
	{
		return EXIT_FAILURE;
	}
	musicMenu.setVolume(40);
	musicMenu.setLoop(true);

	// Stage 1 sound
	sf::Music musicStage1;
	if (!musicStage1.openFromFile("sound/stage1OST.ogg"))
	{
		return EXIT_FAILURE;
	}
	musicStage1.setVolume(40);
	musicStage1.setLoop(true);

	// Stage 2 sound
	sf::Music musicStage2;
	if (!musicStage2.openFromFile("sound/stage2OST.ogg"))
	{
		return EXIT_FAILURE;
	}
	musicStage2.setVolume(40);
	musicStage2.setLoop(true);

	// Stage 3 sound
	sf::Music musicStage3;
	if (!musicStage3.openFromFile("sound/stage3OST.ogg"))
	{
		return EXIT_FAILURE;
	}
	musicStage3.setVolume(40);
	musicStage3.setLoop(true);

	// Game Over sound
	sf::Music musicGameOver;
	if (!musicGameOver.openFromFile("sound/gameoverOST.ogg"))
	{
		return EXIT_FAILURE;
	}
	musicGameOver.setVolume(40);
	musicGameOver.setLoop(true);

	// Victory sound
	sf::Music musicVictory;
	if (!musicVictory.openFromFile("sound/victoryOST.ogg"))
	{
		return EXIT_FAILURE;
	}
	musicVictory.setVolume(40);
	musicVictory.setLoop(true);

	// Sound Menu Button
	sf::SoundBuffer buffermenubutton;
	if (!buffermenubutton.loadFromFile("sound/menubutton.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundmenubutton;
	soundmenubutton.setBuffer(buffermenubutton);

	// Sound Menu Confirm
	sf::SoundBuffer buffermenuconfirm;
	if (!buffermenuconfirm.loadFromFile("sound/menuconfirm.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundmenuconfirm;
	soundmenuconfirm.setBuffer(buffermenuconfirm);

	// Sound Monsters Death
	sf::SoundBuffer bufferkill;
	if (!bufferkill.loadFromFile("sound/painp.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundkill;
	soundkill.setBuffer(bufferkill);

	// Sound Slash
	sf::SoundBuffer bufferslash;
	if (!bufferslash.loadFromFile("sound/slash.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundslash;
	soundslash.setBuffer(bufferslash);

	// Sound Bomb
	sf::SoundBuffer bufferbomb;
	if (!bufferbomb.loadFromFile("sound/bomb.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundbomb;
	soundbomb.setBuffer(bufferbomb);

	// Sound Player Shoot
	sf::SoundBuffer buffershoot;
	if (!buffershoot.loadFromFile("sound/shouldershoot.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundshoot;
	soundshoot.setBuffer(buffershoot);

	// Sound Player Plasma
	sf::SoundBuffer bufferplasma;
	if (!bufferplasma.loadFromFile("sound/plasma.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundplasma;
	soundplasma.setBuffer(bufferplasma);

	// Sound Player  Get Hit
	sf::SoundBuffer bufferhit;
	if (!bufferhit.loadFromFile("sound/hit.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundhit;
	soundhit.setBuffer(bufferhit);

	// Sound Collect Coin
	sf::SoundBuffer buffercoin;
	if (!buffercoin.loadFromFile("sound/coin.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundcoin;
	soundcoin.setBuffer(buffercoin);

	// Sound Collect Gun
	sf::SoundBuffer bufferguncoin;
	if (!bufferguncoin.loadFromFile("sound/reload.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundguncoin;
	soundguncoin.setBuffer(bufferguncoin);

	// Sound Collect Aid
	sf::SoundBuffer bufferaidcoin;
	if (!bufferaidcoin.loadFromFile("sound/heal.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundaidcoin;
	soundaidcoin.setBuffer(bufferaidcoin);

	//----------------------------------------------------------------------------------------------------------------------------------------
	
	
	// Player Object
	class player Player1;
	Player1.sprite.setTexture(texturePlayer);
	Player1.sprite.setPosition(920, 540);

	// Monster Vector Array
	vector<enemy>::const_iterator iterMonster;
	vector<enemy> monsterArray;

	// HP Monster Vector Array
	vector<enemy>::const_iterator iterHPMonster;
	vector<enemy> HPmonsterArray;

	// Shooter Vector Array
	vector<enemy>::const_iterator iterShooter;
	vector<enemy> shooterArray;

	// HP Shooter Vector Array
	vector<enemy>::const_iterator iterHPshooter;
	vector<enemy> HPshooterArray;
	
	// Lavar Vector Array
	vector<enemy>::const_iterator iterLavar;
	vector<enemy> lavarArray;

	// HP Lavar Vector Array
	vector<enemy>::const_iterator iterHPLavar;
	vector<enemy> HPlavarArray;

	// Monster Object
	class enemy enemy1;
	enemy1.sprite.setTexture(textureMonster);
	enemy1.rect.setPosition(generateRandom(1800), generateRandom(900));
	monsterArray.push_back(enemy1);
	
	//Shooter Object
	class enemy enemy2;
	enemy2.sprite.setTexture(textureShooter);
	enemy2.rect.setPosition(rand()%1800, rand()%900);
	shooterArray.push_back(enemy2);

	//Lavar Object
	class enemy enemy3;
	enemy3.sprite.setTexture(textureLavar);
	enemy3.rect.setPosition(rand() % 1800, rand() % 900);
	lavarArray.push_back(enemy3);

	//Boss Object
	class enemy enemy4;
	enemy4.sprite.setTexture(textureBoss);
	enemy4.rect.setPosition(500,500);
	enemy4.rect.setSize(sf::Vector2f(160, 160));


	// Enemy1 HP Object
	class enemy enemy1HP;
	enemy1HP.sprite.setTexture(textureHPr);
	HPmonsterArray.push_back(enemy1HP);

	// Enemy2 HP Object
	class enemy enemy2HP;
	enemy2HP.sprite.setTexture(textureHPr);
	HPshooterArray.push_back(enemy2HP);

	// Enemy3 HP Object
	class enemy enemy3HP;
	enemy3HP.sprite.setTexture(textureHPr);
	HPlavarArray.push_back(enemy3HP);

	// Enemy4 HP Object
	class enemy enemy4HPr;
	enemy4HPr.sprite.setTexture(textureHPr);
	enemy4HPr.sprite.setPosition(300, 900);;

	// Enemy4 HP Object
	class enemy enemy4HPb;
	enemy4HPb.sprite.setTexture(textureHPb);
	enemy4HPb.sprite.setPosition(300, 900);;

    // Projectile Vector Array
	vector<Projectile>::const_iterator iter;
	vector<Projectile> projectileArray;
	
	// Projectile Object
	class Projectile projectile1;
	projectile1.sprite.setTexture(textureBullet);

	// Projectile Vector Array
	vector<Projectile>::const_iterator iterPlasma;
	vector<Projectile> plasmaArray;

	// Projectile Object
	class Projectile projectile2;
	projectile2.sprite.setTexture(texturePlasma);



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	// Loop Game 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (level == 0)
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Down && loadingScene == false)
					{
						keyDown = true;
					}
					if (event.key.code == sf::Keyboard::Up && loadingScene == false)
					{
						keyUp = true;
					}
					if (event.key.code == sf::Keyboard::Left && loadingScene == false)
					{
						keyLeft = true;
					}
					if (event.key.code == sf::Keyboard::Right && loadingScene == false)
					{
						keyRight = true;
					}
					if (event.key.code == sf::Keyboard::Escape && loadingScene == false)
					{
						window.close();
					}
				}
			}

			if (level == 313)
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape && loadingScene == false)
					{
						level = 0;
					}
				}
			}

			if (level == 326)
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Left && loadingScene == false)
					{
						keyLeft = true;
					}
					if (event.key.code == sf::Keyboard::Right && loadingScene == false)
					{
						keyRight = true;
					}
					if (event.key.code == sf::Keyboard::Escape && loadingScene == false)
					{
						level = 0;
					}
				}
			}

			if (level == 339)
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Enter && loadingScene == false)
					{
						soundmenuconfirm.play();
						counterExtra++;
					}
					if (event.key.code == sf::Keyboard::Escape && loadingScene == false)
					{
						level = 0;
					}
				}
			}

			if (level == 1 || level == 2 || level == 3)
			{
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Escape && loadingScene2 == false && loadingScene3 == false)
					{
						window.close();
					}
					if (event.key.code == sf::Keyboard::Space && loadingScene2 == false && loadingScene3 == false)
					{
						keyspace = 1;
						playerattackswordtime = clock.getElapsedTime().asMilliseconds();
						soundslash.play();
					}
					if (event.key.code == sf::Keyboard::R && level == 1)
					{
						pause = true;
						formLevel1 = true;
						level = 444;
					}
					if (event.key.code == sf::Keyboard::R && level == 2)
					{
						pause = true;
						formLevel2 = true;
						level = 444;
					}
					if (event.key.code == sf::Keyboard::R && level == 3)
					{
						pause = true;
						formLevel3 = true;
						level = 444;
					}
					if (event.key.code == sf::Keyboard::C && loadingScene2 == false && loadingScene3 == false)
					{
						keyC = 1;
					}
					if (event.key.code == sf::Keyboard::Up)
					{
						Player1.canMoveUp = false;
					}
					if (event.key.code == sf::Keyboard::Down)
					{
						Player1.canMoveDown = false;
					}
					if (event.key.code == sf::Keyboard::Left)
					{
						Player1.canMoveLeft = false;
					}
					if (event.key.code == sf::Keyboard::Right)
					{
						Player1.canMoveRight = false;
					}
				}
			}

			if (level == 444)
			{
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Enter && formLevel1 == true)
					{
						play = true;
						formLevel1 = false;
						level = 1;
					}
					if (event.key.code == sf::Keyboard::Enter && formLevel2 == true)
					{
						play = true;
						formLevel2 = false;
						level = 2;
					}
					if (event.key.code == sf::Keyboard::Enter && formLevel3 == true)
					{
						play = true;
						formLevel3 = false;
						level = 3;
					}
					if (event.key.code == sf::Keyboard::Escape)
					{
						goExit = true;
					}
				}
			}
			
			if (level == 555)
			{
				switch (event.type)
				{
				case sf::Event::KeyReleased:

					if (event.key.code == sf::Keyboard::Enter)
					{
						saveScore = true;
					}
				}
			}

			if (level == 999)
			{
				switch (event.type)
				{
				case sf::Event::KeyReleased:

					if (event.key.code == sf::Keyboard::Enter)
					{
						level = 0;
						sf::View view2(sf::FloatRect(200, 200, 300, 200));
						view2.setSize(sf::Vector2f(1920, 1080));
						view2.setCenter(sf::Vector2f(view2.getSize().x / 2, view2.getSize().y / 2));
						window.setView(view2);
					}
				}
			}
		}
		



		// Main Menu
		if (level == 0)
		{
			// Music Play
			if (restarttimelevel0 == 1)
			{
				clock.restart();
				musicGameOver.stop();
				musicVictory.stop();
				musicMenu.play();
				restarttimelevel0 = 0;
			}

			//Draw Menu Background
			window.draw(spriteBackgroundMenu);

			// Draw Text on Menu
			window.draw(textStart);
			window.draw(textScore);
			window.draw(textSetting);
			window.draw(textExtra);
			window.draw(textExit);

			// Draw Creator Name
			window.draw(textMyName);

			// Check Keyboard Input
			if (keyDown == true)
			{
				soundmenubutton.play();
				counterMenu++;
				if (counterMenu > 5)
				{
					counterMenu = 1;
				}
				keyDown = false;
			}
			if (keyUp == true)
			{
				soundmenubutton.play();
				counterMenu--;
				if (counterMenu < 1)
				{
					counterMenu = 5;
				}
				keyUp = false;
			}

			// Check Menu State
			if (counterMenu == 1)
			{
				startButton = true;
				scoreButton = false;
				settingButton = false;
				extraButton = false;
				exitButton = false;
			}
			if (counterMenu == 2)
			{
				startButton = false;
				scoreButton = true;
				settingButton = false;
				extraButton = false;
				exitButton = false;
			}
			if (counterMenu == 3)
			{
				startButton = false;
				scoreButton = false;
				settingButton = true;
				extraButton = false;
				exitButton = false;
			}
			if (counterMenu == 4)
			{
				startButton = false;
				scoreButton = false;
				settingButton = false;
				extraButton = true;
				exitButton = false;
			}
			if (counterMenu == 5)
			{
				startButton = false;
				scoreButton = false;
				settingButton = false;
				extraButton = false;
				exitButton = true;
			}
			
            // Change Bold and underlined
			if (startButton == true)
			{
				textStart.setStyle(sf::Text::Bold | sf::Text::Underlined);
				textScore.setStyle(sf::Text::Regular);
				textSetting.setStyle(sf::Text::Regular);
				textExtra.setStyle(sf::Text::Regular);
				textExit.setStyle(sf::Text::Regular);
			}
			if (scoreButton == true)
			{
				textStart.setStyle(sf::Text::Regular);
				textScore.setStyle(sf::Text::Bold | sf::Text::Underlined);
				textSetting.setStyle(sf::Text::Regular);
				textExtra.setStyle(sf::Text::Regular);
				textExit.setStyle(sf::Text::Regular);
			}
			if (settingButton == true)
			{
				textStart.setStyle(sf::Text::Regular);
				textScore.setStyle(sf::Text::Regular);
				textSetting.setStyle(sf::Text::Bold | sf::Text::Underlined);
				textExtra.setStyle(sf::Text::Regular);
				textExit.setStyle(sf::Text::Regular);
			}
			if (extraButton == true)
			{
				textStart.setStyle(sf::Text::Regular);
				textScore.setStyle(sf::Text::Regular);
				textSetting.setStyle(sf::Text::Regular);
				textExtra.setStyle(sf::Text::Bold | sf::Text::Underlined);
				textExit.setStyle(sf::Text::Regular);
			}
			if (exitButton == true)
			{
				textStart.setStyle(sf::Text::Regular);
				textScore.setStyle(sf::Text::Regular);
				textSetting.setStyle(sf::Text::Regular);
				textExtra.setStyle(sf::Text::Regular);
				textExit.setStyle(sf::Text::Bold | sf::Text::Underlined);
			}

			//Event When Pressed Enter
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && counterMenu == 1 && loadingScene == false)
			{
				soundmenuconfirm.play();
				loadingScene = true;
				restartTimeLoadingScene = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && counterMenu == 2 && loadingScene == false)
			{
				soundmenuconfirm.play();
				showScore = true;
				level = 313;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && counterMenu == 3 && loadingScene == false)
			{
				soundmenuconfirm.play();
				level = 326;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && counterMenu == 4 && loadingScene == false)
			{
				soundmenuconfirm.play();
				level = 339;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && counterMenu == 5 && loadingScene == false)
			{
				window.close();
			}

			// Cheat Code
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				enterG = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && enterG == true)
			{
				enterO = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && enterO == true)
			{
				enterD = true;
			}
			if (enterD == true)
			{
				Player1.blood = 99999999;
				enterG = false;
				enterO = false;
				enterD = false;
			}

		}

		// Score
		if (level == 313)
		{
			window.draw(spriteScore);
			window.draw(textScoreLine1);
			window.draw(textScoreLine2);
			window.draw(textScoreLine3);
			window.draw(textScoreLine4);
			window.draw(textScoreLine5);
			window.draw(textNameLine1);
			window.draw(textNameLine2);
			window.draw(textNameLine3);
			window.draw(textNameLine4);
			window.draw(textNameLine5);
			if (showScore == true)
			{
				ifstream myfile;
				myfile.open("name.txt");
				string name[100];
				string lineName;
				int tempIndexName = 0;
				while (getline(myfile, lineName))
				{
					name[++tempIndexName] = lineName;
				}
				myfile.close();

				ifstream myfile2;
				myfile2.open("score.txt");
				char scoree[100];
				int scorePoint[100];
				string lineScore;
				int tempIndexScore = 0;
				int max = -99999999;
			
				while (getline(myfile2, lineScore))
				{
					scorePoint[++tempIndexScore] = stoi(lineScore);
					
				}
				myfile2.close();
				
				// Line 1
				string nameNumber1;
				for (int score_1 = 1; score_1 < 100; score_1++)
				{
					if (scorePoint[score_1] > max)
					{
						max = scorePoint[score_1];
						nameNumber1 = name[score_1];
					}
				}		
				string scoreNumber1;
				scoreNumber1 = to_string(max);
				textScoreLine1.setPosition(1270, 370);
				textScoreLine1.setString(scoreNumber1);
				textNameLine1.setPosition(140, 370);
				textNameLine1.setString(nameNumber1);
			

				string nameNumber2;
				// Line 2
				int max2 = -99999999;
				for (int score_2 = 1; score_2 < 100; score_2++)
				{
					if (scorePoint[score_2] > max2 && scorePoint[score_2] != max)
					{
						max2 = scorePoint[score_2];
						nameNumber2 = name[score_2];
					}
				}
				string scoreNumber2;
				scoreNumber2 = to_string(max2);
				textScoreLine2.setPosition(1270, 465);
				textScoreLine2.setString(scoreNumber2);
				textNameLine2.setPosition(140, 465);
				textNameLine2.setString(nameNumber2);

				// Line 3
				string nameNumber3;
				int max3 = -99999999;
				for (int score_3 = 1; score_3 < 100; score_3++)
				{
					if (scorePoint[score_3] > max3 && scorePoint[score_3] != max && scorePoint[score_3] != max2)
					{
						max3 = scorePoint[score_3];
						nameNumber3 = name[score_3];
					}
				}
				string scoreNumber3;
				scoreNumber3 = to_string(max3);
				textScoreLine3.setPosition(1270, 560);
				textScoreLine3.setString(scoreNumber3);
				textNameLine3.setPosition(140, 560);
				textNameLine3.setString(nameNumber3);

				// Line 4
				string nameNumber4;
				int max4 = -99999999;
				for (int score_4 = 1; score_4 < 100; score_4++)
				{
					if (scorePoint[score_4] > max4 && scorePoint[score_4] != max && scorePoint[score_4] != max2 && scorePoint[score_4] != max3)
					{
						max4 = scorePoint[score_4];
						nameNumber4 = name[score_4];
					}
				}
				string scoreNumber4;
				scoreNumber4 = to_string(max4);
				textScoreLine4.setPosition(1270, 655);
				textScoreLine4.setString(scoreNumber4);
				textNameLine4.setPosition(140, 655);
				textNameLine4.setString(nameNumber4);

				// Line 5
				string nameNumber5;
				int max5 = -99999999;
				for (int score_5 = 1; score_5 < 100; score_5++)
				{
					if (scorePoint[score_5] > max5 && scorePoint[score_5] != max && scorePoint[score_5] != max2 && scorePoint[score_5] != max3 && scorePoint[score_5] != max4)
					{
						max5 = scorePoint[score_5];
						nameNumber5 = name[score_5];
					}
				}
				string scoreNumber5;
				scoreNumber5 = to_string(max5);
				textScoreLine5.setPosition(1270, 750);
				textScoreLine5.setString(scoreNumber5);
				textNameLine5.setPosition(140, 750);
				textNameLine5.setString(nameNumber5);

				showScore = false;
			}
		}

		// Setting
		if (level == 326)
		{
			window.draw(spriteSetting);
			window.draw(textSoundOn);
			window.draw(textSoundOff);
			// Check Keyboard Input
			if (keyRight == true)
			{
				soundmenubutton.play();
				counterSetting++;
				if (counterSetting > 5)
				{
					counterSetting = 1;
				}
				keyRight = false;
			}
			if (keyLeft == true)
			{
				soundmenubutton.play();
				counterSetting--;
				if (counterSetting < 1)
				{
					counterSetting = 5;
				}
				keyLeft = false;
			}
			if (counterSetting == 1)
			{
				soundOnButton = true;
				soundOffButton = false;
			}
			if (counterSetting == 2)
			{
				soundOnButton = false;
				soundOffButton = true;
			}
		

			// Change Bold and underlined
			if (soundOnButton == true)
			{
				textSoundOn.setStyle(sf::Text::Bold | sf::Text::Underlined);
				textSoundOff.setStyle(sf::Text::Regular);
			}
			if (soundOffButton == true)
			{
				textSoundOn.setStyle(sf::Text::Regular);
				textSoundOff.setStyle(sf::Text::Bold | sf::Text::Underlined);
			}

			// Event When Pressed Enter
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && counterSetting == 1))
			{
				soundmenuconfirm.play();
				musicMenu.setVolume(40);
				musicStage1.setVolume(40);
				musicStage2.setVolume(40);
				musicStage3.setVolume(40);
				musicVictory.setVolume(40);
				musicGameOver.setVolume(40);
				soundmenubutton.setVolume(100);
				soundmenuconfirm.setVolume(100);
				soundkill.setVolume(100);
				soundslash.setVolume(100);
				soundbomb.setVolume(100);
				soundshoot.setVolume(100);
				soundplasma.setVolume(100);
				soundhit.setVolume(100);
				soundcoin.setVolume(100);
				soundaidcoin.setVolume(100);
				soundguncoin.setVolume(100);
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && counterSetting == 2))
			{
				soundmenuconfirm.play();
				musicMenu.setVolume(0);
				musicStage1.setVolume(0);
				musicStage2.setVolume(0);
				musicStage3.setVolume(0);
				musicVictory.setVolume(0);
				musicGameOver.setVolume(0);
				soundmenubutton.setVolume(0);
				soundmenuconfirm.setVolume(0);
				soundkill.setVolume(0);
				soundslash.setVolume(0);
				soundbomb.setVolume(0);
				soundshoot.setVolume(0);
				soundplasma.setVolume(0);
				soundhit.setVolume(0);
				soundcoin.setVolume(0);
				soundaidcoin.setVolume(0);
				soundguncoin.setVolume(0);
			}
		}

		// Extra
		if (level == 339)
		{
			if (counterExtra == 1)
			{
				window.draw(spriteCharacter);
			}
			if (counterExtra == 2)
			{
				window.draw(spriteItem);
			}
			if (counterExtra > 2)
			{
				counterExtra = 1;
			}
		}


		// Loading Scene
		if (loadingScene == true)
		{
			musicMenu.pause();
			if (tutorial == false)
			{
				window.draw(spriteControl);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				soundmenuconfirm.play();
				mission = true;
			}
			if (mission == true)
			{
				window.draw(spriteMission);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					soundmenuconfirm.play();
					mission = false;
					collect = true;
				}
			}
			if (collect == true)
			{
				window.draw(spriteCollect);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					soundmenuconfirm.play();
					collect = false;
					howtoplay = true;
				}
			}
			
			if (howtoplay == true)
			{
				window.draw(spriteHowtoplay);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					soundmenuconfirm.play();
					howtoplay = false;
					tutorial = true;
				}
			}
		
			if (tutorial == true)
			{
				if (restartTimeLoadingScene == true)
				{
					clock.restart();
						restartTimeLoadingScene = false;
				}
				timerLoadingScene = clock.getElapsedTime().asSeconds();
				if (timerLoadingScene < 5.00)
				{
					window.draw(spriteLoadingSceneLevel1);
					enemy4.rect.setPosition(100, 100);
					Player1.sprite.setPosition(1920 / 2, 1080 / 2);
				}
				else
				{
					level = 1;
					loadingScene = false;
					tutorial = false;
				}
			}
		}



		// level 1
		if (level == 1)
		{
			loadingScene = false;
			if (restarttimelevel1 == 1)
			{
				clock.restart();
				musicStage1.play();
				musicStage1.setLoop(true);
				restarttimelevel1 = 0;
			}
			// timer 
			timerlevel1milli = clock.getElapsedTime().asMilliseconds();
			if (pause == false)
			{	
				gtime1 = ctime1;
				ctime1 = clock.getElapsedTime().asSeconds();
				if (gtime1 != ctime1)
				{
					enterTimeLevel1 = true;
				}
				
				if (ctime1 % 1 == 0 && enterTimeLevel1 == true) 
				{
					if (pause == false)
					{
						timerlevel1++;
					}
					enterTimeLevel1 = false;
				}

			}
			// Pause
			if (pause == true)
			{
				if (play == true)
				{
					pause = false;
					play = false;
				}
			}


			if (int(timerlevel1) % 1 == 0 && enterTime1 == 1)
			{
				nowtimelevel1 = timerlevel1;
				_itoa_s(int(timerlevel1), bufferTimeLevel1, 10);
				enterTime1 = 0;
			}

			aftercounttimelevel1 = timerlevel1;
			if (aftercounttimelevel1 - nowtimelevel1 >= 1)
			{
				enterTime1 = 1;
			}


			// view
			window.setView(view1);
			

			// player sword attack
			if (keyspace == 1)
			{
				deltatimeplayerattacksword = timerlevel1milli - playerattackswordtime;
				if (deltatimeplayerattacksword < 150)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 640, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 512, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 768, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 896, 128, 128));
					}
				}
				if (deltatimeplayerattacksword >= 150 && deltatimeplayerattacksword < 300)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 640, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 512, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 768, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 896, 128, 128));
					}
				}
				if (deltatimeplayerattacksword >= 300 && deltatimeplayerattacksword < 450)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 640, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 512, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 768, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 896, 128, 128));
					}
				}
				if (deltatimeplayerattacksword > 450)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 128, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 256, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 384, 128, 128));
					}
					keyspace = 0;
				}
			}


			window.clear();
			window.draw(spriteLevel1BehideBackground);
			window.draw(spriteLevel1Background);


			

			if (drawPlayerBeforeEnemy == true)
			{
				// Draw Player
				window.draw(Player1.sprite);
				window.draw(spriteShoulderCannon);


				// Draw Monster
			
				counter = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					if (counter != 0)
					{
						monsterArray[counter].update();
						enemy1.rect.setPosition(generateRandom(1920), generateRandom(1080));
						window.draw(monsterArray[counter].sprite);	
					}
					counter++;
				}
				
				
				// Draw Shooter
				counterShooter = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					if (counterShooter != 0)
					{
						shooterArray[counterShooter].update();
						enemy2.rect.setPosition(rand() % 1800, rand() % 900);
						window.draw(shooterArray[counterShooter].sprite);
					}
					counterShooter++;
				}
			}

			if (drawPlayerBeforeEnemy == false)
			{
				// Draw Monster
				
					counter = 0;
					for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
					{
						if (counter != 0)
						{
							monsterArray[counter].update();
							enemy1.rect.setPosition(generateRandom(1920), generateRandom(1080));
							window.draw(monsterArray[counter].sprite);
						}
						counter++;
						
					}

					// Draw Shooter
					
					counterShooter = 0;
					for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
					{
						if (counterShooter != 0)
						{
							shooterArray[counterShooter].update();
							enemy2.rect.setPosition(rand() % 1800, rand() % 900);
							window.draw(shooterArray[counterShooter].sprite);
						}
						counterShooter++;
					}
					
				
				window.draw(Player1.sprite);
				window.draw(spriteShoulderCannon);
			}

			// Draw HP Monster
			counter = 0;
			for (iterHPMonster = HPmonsterArray.begin(); iterHPMonster != HPmonsterArray.end(); iterHPMonster++)
			{
				if (counter != 0)
				{
					HPmonsterArray[counter].update();
					HPmonsterArray[counter].sprite.setPosition(monsterArray[counter].sprite.getPosition().x, monsterArray[counter].sprite.getPosition().y - 20);
					window.draw(HPmonsterArray[counter].sprite);
				}
				counter++;
			}
			
			// Draw HP Shooter
			counter = 0;
			for (iterHPshooter = HPshooterArray.begin(); iterHPshooter != HPshooterArray.end(); iterHPshooter++)
			{
				if (counter != 0)
				{
					HPshooterArray[counter].update();
					HPshooterArray[counter].sprite.setPosition(shooterArray[counter].sprite.getPosition().x, shooterArray[counter].sprite.getPosition().y - 20);
					window.draw(HPshooterArray[counter].sprite);
				}
				counter++;
			}
			
			// Update Player
			Player1.update();
			Player1.updateMovement();


			// Player View
			window.setView(view1);
			view1.setCenter(Player1.sprite.getPosition());

			// Delete All Monster
			if (goExit == true || loadingScene2 == true)
			{
				counterM = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					monsterArray[counterM].alive = false;
					HPmonsterArray[counterM].alive = false;
					counterM++;
				}

				counterS = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					shooterArray[counterS].alive = false;
					HPshooterArray[counterS].alive = false;
					counterS++;
				}

				counterL = 0;
				for (iterLavar = lavarArray.begin(); iterLavar != lavarArray.end(); iterLavar++)
				{
					lavarArray[counterL].alive = false;
					HPlavarArray[counterL].alive = false;
					counterL++;
				}

				counterP = 0;
				for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
				{
					plasmaArray[counterP].destroy = true;
					counterP++;
				}

				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					projectileArray[counter].destroy = true;
					counter++;
				}
			}

			// Monster Chase And Attack
			counterM = 0;
			for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
			{
				if (counterM != 0)
				{
					timerMonster = clock.getElapsedTime().asMilliseconds();
					if (timerMonster % 50 == 0)
					{
						monsterArray[counterM].tempMonsterRand = rand() % 2;
					}
					if (monsterArray[counterM].tempMonsterRand == 0)
					{
						if (Player1.sprite.getPosition().y < monsterArray[counterM].rect.getPosition().y)
						{
							drawPlayerBeforeEnemy = true;
							if (int(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
							{
								monsterArray[counterM].counterWalkingMonster++;
							}
							if (monsterArray[counterM].monsterCanMoveUp == true)
							{
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 96, 96, 96));

								if (monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 10)
								{
									monsterArray[counterM].rect.move(0, -1);;
								}
								else
								{
									monsterArray[counterM].rect.move(0, -enemy1.movementSpeed);
								}
							}
							if (monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x < 40) && abs(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
							{
								monsterArray[counterM].monsterCanMoveUp = false;
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 672, 96, 96));
								monsterArray[counterM].counterMonsterAttack++;
								if (monsterArray[counterM].enterMonsterArrive == true)
								{
									monsterArray[counterM].timeMonsterArrive = int(timerlevel1);
									monsterArray[counterM].enterMonsterArrive = false;
									monsterArray[counterM].monsterAngry = true;
									Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
								}
								if ((int(timerlevel1) - monsterArray[counterM].timeMonsterArrive) % 2 == 0 && monsterArray[counterM].monsterAngry == true)
								{
									monsterArray[counterM].enterMonsterAttack = true;
									monsterArray[counterM].monsterAngry = false;
								}
								if (monsterArray[counterM].enterMonsterAttack == true)
								{
									soundhit.play();
									Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
									monsterArray[counterM].timeMonsterATK = timerlevel1;
									monsterArray[counterM].monsterAngry = false;
									monsterArray[counterM].enterMonsterAttack = false;

								}
								monsterArray[counterM].afterMonsterArrive = timerlevel1;
								if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 2)
								{
									monsterArray[counterM].monsterAngry = true;
								}

							}
							else
							{
								monsterArray[counterM].monsterCanMoveUp = true;
								monsterArray[counterM].enterMonsterArrive = true;
							}
						}
						else if (Player1.sprite.getPosition().y > monsterArray[counterM].rect.getPosition().y)
						{
							drawPlayerBeforeEnemy = false;
							if (int(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
							{
								monsterArray[counterM].counterWalkingMonster++;
							}
							if (monsterArray[counterM].monsterCanMoveDown == true)
							{
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 0, 96, 96));
								if (Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 10)
								{
									monsterArray[counterM].rect.move(0, 1);
								}
								else
								{
									monsterArray[counterM].rect.move(0, enemy1.movementSpeed);
								}
							}
							if (Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x) < 40 && abs(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
							{
								monsterArray[counterM].monsterCanMoveDown = false;
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 576, 96, 96));
								monsterArray[counterM].counterMonsterAttack++;
								if (monsterArray[counterM].enterMonsterArrive == true)
								{
									monsterArray[counterM].timeMonsterArrive = int(timerlevel1);
									monsterArray[counterM].enterMonsterArrive = false;
									monsterArray[counterM].monsterAngry = true;
									Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
								}
								if ((int(timerlevel1) - monsterArray[counterM].timeMonsterArrive) % 2 == 0 && monsterArray[counterM].monsterAngry == true)
								{
									monsterArray[counterM].enterMonsterAttack = true;
									monsterArray[counterM].monsterAngry = false;
								}
								if (monsterArray[counterM].enterMonsterAttack == true)
								{
									soundhit.play();
									Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
									monsterArray[counterM].timeMonsterATK = timerlevel1;
									monsterArray[counterM].monsterAngry = false;
									monsterArray[counterM].enterMonsterAttack = false;

								}
								monsterArray[counterM].afterMonsterArrive = timerlevel1;
								if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 2)
								{
									monsterArray[counterM].monsterAngry = true;
								}

							}
							else
							{
								monsterArray[counterM].monsterCanMoveDown = true;
								monsterArray[counterM].enterMonsterArrive = true;
							}
						}
						else if (Player1.sprite.getPosition().x > monsterArray[counterM].rect.getPosition().x)
						{
							drawPlayerBeforeEnemy = false;
							if (int(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x) % 5 == 0)
							{
								monsterArray[counterM].counterWalkingMonster++;
							}
							if (monsterArray[counterM].monsterCanMoveRight == true)
							{
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 288, 96, 96));
								monsterArray[counterM].rect.move(enemy1.movementSpeed, 0);
								monsterArray[counterM].enterMonsterArrive = true;
							}
							if (Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 20) && abs(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
							{
								monsterArray[counterM].monsterCanMoveRight = false;
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 480, 96, 96));
								monsterArray[counterM].counterMonsterAttack++;
								if (monsterArray[counterM].enterMonsterArrive == true)
								{
									monsterArray[counterM].timeMonsterArrive = int(timerlevel1);
									monsterArray[counterM].enterMonsterArrive = false;
									monsterArray[counterM].monsterAngry = true;
									Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
								}
								if ((int(timerlevel1) - monsterArray[counterM].timeMonsterArrive) % 1 == 0 && monsterArray[counterM].monsterAngry == true)
								{
									monsterArray[counterM].enterMonsterAttack = true;
									monsterArray[counterM].monsterAngry = false;
								}
								if (monsterArray[counterM].enterMonsterAttack == true)
								{
									soundhit.play();
									Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
									monsterArray[counterM].timeMonsterATK = timerlevel1;
									monsterArray[counterM].monsterAngry = false;
									monsterArray[counterM].enterMonsterAttack = false;

								}
								monsterArray[counterM].afterMonsterArrive = timerlevel1;
								if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 1)
								{
									monsterArray[counterM].monsterAngry = true;
								}
							}
							else
							{
								monsterArray[counterM].monsterCanMoveRight = true;
								monsterArray[counterM].enterMonsterArrive = true;
							}
						}
						else if (Player1.sprite.getPosition().x < monsterArray[counterM].rect.getPosition().x)
						{
							drawPlayerBeforeEnemy = false;
							if (int(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x) % 5 == 0)
							{
								monsterArray[counterM].counterWalkingMonster++;
							}
							if (monsterArray[counterM].monsterCanMoveLeft == true)
							{
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 192, 96, 96));
								monsterArray[counterM].rect.move(-enemy1.movementSpeed, 0);
							}
							if (monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 20) && abs(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
							{
								monsterArray[counterM].monsterCanMoveLeft = false;
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 384, 96, 96));
								monsterArray[counterM].counterMonsterAttack++;
								if (monsterArray[counterM].enterMonsterArrive == true)
								{
									monsterArray[counterM].timeMonsterArrive = int(timerlevel1);
									monsterArray[counterM].enterMonsterArrive = false;
									monsterArray[counterM].monsterAngry = true;
									Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
								}
								if ((int(timerlevel1) - monsterArray[counterM].timeMonsterArrive) % 1 == 0 && monsterArray[counterM].monsterAngry == true)
								{
									monsterArray[counterM].enterMonsterAttack = true;
									monsterArray[counterM].monsterAngry = false;
								}
								if (monsterArray[counterM].enterMonsterAttack == true)
								{
									soundhit.play();
									Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
									monsterArray[counterM].timeMonsterATK = timerlevel1;
									monsterArray[counterM].monsterAngry = false;
									monsterArray[counterM].enterMonsterAttack = false;

								}
								monsterArray[counterM].afterMonsterArrive = timerlevel1;
								if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 1)
								{
									monsterArray[counterM].monsterAngry = true;
								}

							}
							else
							{
								monsterArray[counterM].monsterCanMoveLeft = true;
								monsterArray[counterM].enterMonsterArrive = true;
							}
						}
					}

					if (monsterArray[counterM].tempMonsterRand == 1)
					{
						if (Player1.sprite.getPosition().x > monsterArray[counterM].rect.getPosition().x)
						{
							drawPlayerBeforeEnemy = false;
							if ((int(Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x) % 5 == 0))
							{
								monsterArray[counterM].counterWalkingMonster++;
							}
							if (monsterArray[counterM].monsterCanMoveRight == true)
							{
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 288, 96, 96));
								if (Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x < 10)
								{
									monsterArray[counterM].rect.move(1, 0);;
								}
								else
								{
									monsterArray[counterM].rect.move(enemy1.movementSpeed, 0);
								}
								monsterArray[counterM].enterMonsterArrive = true;
							}
							if (Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 20) && abs(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
							{
								monsterArray[counterM].monsterCanMoveRight = false;
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 480, 96, 96));
								monsterArray[counterM].counterMonsterAttack++;

								if (monsterArray[counterM].enterMonsterArrive == true)
								{
									monsterArray[counterM].timeMonsterArrive = int(timerlevel1);
									monsterArray[counterM].enterMonsterArrive = false;
									monsterArray[counterM].monsterAngry = true;
									Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
								}
								if ((int(timerlevel1) - monsterArray[counterM].timeMonsterArrive) % 1 == 0 && monsterArray[counterM].monsterAngry == true)
								{
									monsterArray[counterM].enterMonsterAttack = true;
									monsterArray[counterM].monsterAngry = false;
								}
								if (monsterArray[counterM].enterMonsterAttack == true)
								{
									soundhit.play();
									Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
									monsterArray[counterM].timeMonsterATK = timerlevel1;
									monsterArray[counterM].monsterAngry = false;
									monsterArray[counterM].enterMonsterAttack = false;

								}
								monsterArray[counterM].afterMonsterArrive = timerlevel1;
								if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 1)
								{
									monsterArray[counterM].monsterAngry = true;
								}
							}
							else
							{
								monsterArray[counterM].monsterCanMoveRight = true;
								monsterArray[counterM].enterMonsterArrive = true;
							}
						}
						else if (Player1.sprite.getPosition().x < monsterArray[counterM].rect.getPosition().x)
						{
							drawPlayerBeforeEnemy = false;
							if (int(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x) % 5 == 0)
							{
								monsterArray[counterM].counterWalkingMonster++;
							}
							if (monsterArray[counterM].monsterCanMoveLeft == true)
							{
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 192, 96, 96));
								if (monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 10)
								{
									monsterArray[counterM].rect.move(-1, 0);;
								}
								else
								{
									monsterArray[counterM].rect.move(-enemy1.movementSpeed, 0);
								}
							}
							if (monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 20) && abs(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
							{
								monsterArray[counterM].monsterCanMoveLeft = false;
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 384, 96, 96));
								monsterArray[counterM].counterMonsterAttack++;
								if (monsterArray[counterM].enterMonsterArrive == true)
								{
									monsterArray[counterM].timeMonsterArrive = int(timerlevel1);
									monsterArray[counterM].enterMonsterArrive = false;
									monsterArray[counterM].monsterAngry = true;
									Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
								}
								if ((int(timerlevel1) - monsterArray[counterM].timeMonsterArrive) % 1 == 0 && monsterArray[counterM].monsterAngry == true)
								{
									monsterArray[counterM].enterMonsterAttack = true;
									monsterArray[counterM].monsterAngry = false;
								}
								if (monsterArray[counterM].enterMonsterAttack == true)
								{
									soundhit.play();
									Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
									monsterArray[counterM].timeMonsterATK = timerlevel1;
									monsterArray[counterM].monsterAngry = false;
									monsterArray[counterM].enterMonsterAttack = false;

								}
								monsterArray[counterM].afterMonsterArrive = timerlevel1;
								if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 1)
								{
									monsterArray[counterM].monsterAngry = true;
								}

							}
							else
							{
								monsterArray[counterM].monsterCanMoveLeft = true;
								monsterArray[counterM].enterMonsterArrive = true;
							}
						}
						else if (Player1.sprite.getPosition().y < monsterArray[counterM].rect.getPosition().y)
						{
							drawPlayerBeforeEnemy = true;
							if (int(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
							{
								monsterArray[counterM].counterWalkingMonster++;
							}
							if (monsterArray[counterM].monsterCanMoveUp == true)
							{
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 96, 96, 96));

								if (monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 10)
								{
									monsterArray[counterM].rect.move(0, -1);;
								}
								else
								{
									monsterArray[counterM].rect.move(0, -enemy1.movementSpeed);
								}
							}
							if (monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x < 40) && abs(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
							{
								monsterArray[counterM].monsterCanMoveUp = false;
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 672, 96, 96));
								monsterArray[counterM].counterMonsterAttack++;
								if (monsterArray[counterM].enterMonsterArrive == true)
								{
									monsterArray[counterM].timeMonsterArrive = int(timerlevel1);
									monsterArray[counterM].enterMonsterArrive = false;
									monsterArray[counterM].monsterAngry = true;
									Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
								}
								if ((int(timerlevel1) - monsterArray[counterM].timeMonsterArrive) % 2 == 0 && monsterArray[counterM].monsterAngry == true)
								{
									monsterArray[counterM].enterMonsterAttack = true;
									monsterArray[counterM].monsterAngry = false;
								}
								if (monsterArray[counterM].enterMonsterAttack == true)
								{
									soundhit.play();
									Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
									monsterArray[counterM].timeMonsterATK = timerlevel1;
									monsterArray[counterM].monsterAngry = false;
									monsterArray[counterM].enterMonsterAttack = false;

								}
								monsterArray[counterM].afterMonsterArrive = timerlevel1;
								if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 2)
								{
									monsterArray[counterM].monsterAngry = true;
								}

							}
							else
							{
								monsterArray[counterM].monsterCanMoveUp = true;
								monsterArray[counterM].enterMonsterArrive = true;
							}
						}
						else if (Player1.sprite.getPosition().y > monsterArray[counterM].rect.getPosition().y)
						{
							drawPlayerBeforeEnemy = false;
							if (int(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
							{
								monsterArray[counterM].counterWalkingMonster++;
							}
							if (monsterArray[counterM].monsterCanMoveDown == true)
							{
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 0, 96, 96));
								if (Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 10)
								{
									monsterArray[counterM].rect.move(0, 1);
								}
								else
								{
									monsterArray[counterM].rect.move(0, enemy1.movementSpeed);
								}
							}
							if (Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x) < 40 && abs(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
							{
								monsterArray[counterM].monsterCanMoveDown = false;
								monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 576, 96, 96));
								monsterArray[counterM].counterMonsterAttack++;
								if (monsterArray[counterM].enterMonsterArrive == true)
								{
									monsterArray[counterM].timeMonsterArrive = int(timerlevel1);
									monsterArray[counterM].enterMonsterArrive = false;
									monsterArray[counterM].monsterAngry = true;
									Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
								}
								if ((int(timerlevel1) - monsterArray[counterM].timeMonsterArrive) % 2 == 0 && monsterArray[counterM].monsterAngry == true)
								{
									monsterArray[counterM].enterMonsterAttack = true;
									monsterArray[counterM].monsterAngry = false;
								}
								if (monsterArray[counterM].enterMonsterAttack == true)
								{
									soundhit.play();
									Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
									monsterArray[counterM].timeMonsterATK = timerlevel1;
									monsterArray[counterM].monsterAngry = false;
									monsterArray[counterM].enterMonsterAttack = false;

								}
								monsterArray[counterM].afterMonsterArrive = timerlevel1;
								if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 2)
								{
									monsterArray[counterM].monsterAngry = true;
								}

							}
							else
							{
								monsterArray[counterM].monsterCanMoveDown = true;
								monsterArray[counterM].enterMonsterArrive = true;
							}
						}
					}


					if (monsterArray[counterM].counterWalkingMonster >= 2)
					{
						monsterArray[counterM].counterWalkingMonster = 0;
					}

					if (monsterArray[counterM].counterMonsterAttack >= 2)
					{
						monsterArray[counterM].counterMonsterAttack = 0;
					}
				}
				counterM++;
			}



			// Shooter Chase And Attack
				counterS = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					if (counterS != 0)
					{
						timerShooter = clock.getElapsedTime().asMilliseconds();
						if (timerShooter % 50 == 0)
						{
							shooterArray[counterS].tempShooterRand = rand() % 2;
						}
						if (shooterArray[counterS].tempShooterRand == 0)
						{
							if (Player1.sprite.getPosition().y < shooterArray[counterS].rect.getPosition().y)
							{
								drawPlayerBeforeEnemy = true;
								if (shooterArray[counterS].shooterCanMoveUp == true)
								{
									shooterArray[counterS].sprite.setTextureRect(sf::IntRect(0, 96, 96, 96));

									if (shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 10)
									{
										shooterArray[counterS].rect.move(0, -1);;
									}
									else
									{
										shooterArray[counterS].rect.move(0, -enemy2.movementSpeed - 2);
									}
								}
								if (shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 250 && abs(Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 40) && abs(shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
								{
									shooterArray[counterS].shooterCanMoveUp = false;
									if (shooterArray[counterS].enterShooterArrive == true)
									{
										shooterArray[counterS].timeShooterArrive = int(timerlevel1);
										shooterArray[counterS].enterShooterArrive = false;
										shooterArray[counterS].shooterAngry = true;
										Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
									}
									if ((int(timerlevel1) - shooterArray[counterS].timeShooterArrive) % 2 == 0 && shooterArray[counterS].shooterAngry == true)
									{
										shooterArray[counterS].enterShooterAttack = true;
										shooterArray[counterS].shooterAngry = false;
									}
									if (shooterArray[counterS].enterShooterAttack == true)
									{
										projectile2.shooterPlasma = true;
										projectile2.movementSpeed = 7;
										projectile2.direction = 1;
										projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
										plasmaArray.push_back(projectile2);
										soundplasma.play();
										projectile2.shooterPlasma = false;
										Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
										shooterArray[counterS].timeShooterATK = timerlevel1;
										shooterArray[counterS].shooterAngry = false;
										shooterArray[counterS].enterShooterAttack = false;

									}
									shooterArray[counterS].afterShooterArrive = timerlevel1;
									if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 2)
									{
										shooterArray[counterS].shooterAngry = true;
									}

								}
								else
								{
									shooterArray[counterS].shooterCanMoveUp = true;
									shooterArray[counterS].enterShooterArrive = true;
								}
							}
							else if (Player1.sprite.getPosition().y > shooterArray[counterS].rect.getPosition().y)
							{
								drawPlayerBeforeEnemy = false;
								if (shooterArray[counterS].shooterCanMoveDown == true)
								{
									shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 0, 96, 96));
									if (Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 10)
									{
										shooterArray[counterS].rect.move(0, 1);
									}
									else
									{
										shooterArray[counterS].rect.move(0, enemy2.movementSpeed + 2);
									}
								}
								if (Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 250 && abs(Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x) < 40 && abs(shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
								{
									shooterArray[counterS].shooterCanMoveDown = false;
									if (shooterArray[counterS].enterShooterArrive == true)
									{
										shooterArray[counterS].timeShooterArrive = int(timerlevel1);
										shooterArray[counterS].enterShooterArrive = false;
										shooterArray[counterS].shooterAngry = true;
										Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
									}
									if ((int(timerlevel1) - shooterArray[counterS].timeShooterArrive) % 2 == 0 && shooterArray[counterS].shooterAngry == true)
									{
										shooterArray[counterS].enterShooterAttack = true;
										shooterArray[counterS].shooterAngry = false;
									}
									if (shooterArray[counterS].enterShooterAttack == true)
									{
										projectile2.shooterPlasma = true;
										projectile2.movementSpeed = 7;
										projectile2.direction = 2;
										projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
										plasmaArray.push_back(projectile2);
										soundplasma.play();
										projectile2.shooterPlasma = false;
										Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
										shooterArray[counterS].timeShooterATK = timerlevel1;
										shooterArray[counterS].shooterAngry = false;
										shooterArray[counterS].enterShooterAttack = false;

									}
									shooterArray[counterS].afterShooterArrive = timerlevel1;
									if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 2)
									{
										shooterArray[counterS].shooterAngry = true;
									}
								}
								else
								{
									shooterArray[counterS].shooterCanMoveDown = true;
									shooterArray[counterS].enterShooterArrive = true;
								}
							}
							else if (Player1.sprite.getPosition().x > shooterArray[counterS].rect.getPosition().x)
							{
								drawPlayerBeforeEnemy = false;
								if (shooterArray[counterS].shooterCanMoveRight == true)
								{
									shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 192, 96, 96));
									shooterArray[counterS].rect.move(enemy2.movementSpeed + 2, 0);
									shooterArray[counterS].enterShooterArrive = true;
								}
								if (Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 250 && abs(Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 20) && abs(shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
								{
									shooterArray[counterS].shooterCanMoveRight = false;
									if (shooterArray[counterS].enterShooterArrive == true)
									{
										shooterArray[counterS].timeShooterArrive = int(timerlevel1);
										shooterArray[counterS].enterShooterArrive = false;
										shooterArray[counterS].shooterAngry = true;
										Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
									}
									if ((int(timerlevel1) - shooterArray[counterS].timeShooterArrive) % 1 == 0 && shooterArray[counterS].shooterAngry == true)
									{
										shooterArray[counterS].enterShooterAttack = true;
										shooterArray[counterS].shooterAngry = false;
									}
									if (shooterArray[counterS].enterShooterAttack == true)
									{
										projectile2.shooterPlasma = true;
										projectile2.movementSpeed = 7;
										projectile2.direction = 4;
										projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
										plasmaArray.push_back(projectile2);
										soundplasma.play();
										projectile2.shooterPlasma = false;
										Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
										shooterArray[counterS].timeShooterATK = timerlevel1;
										shooterArray[counterS].shooterAngry = false;
										shooterArray[counterS].enterShooterAttack = false;

									}
									shooterArray[counterS].afterShooterArrive = timerlevel1;
									if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 1)
									{
										shooterArray[counterS].shooterAngry = true;
									}
								}
								else
								{
									shooterArray[counterS].shooterCanMoveRight = true;
									shooterArray[counterS].enterShooterArrive = true;
								}
							}
							else if (Player1.sprite.getPosition().x < shooterArray[counterS].rect.getPosition().x)
							{
								drawPlayerBeforeEnemy = false;
								if (shooterArray[counterS].shooterCanMoveLeft == true)
								{
									shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 288, 96, 96));
									shooterArray[counterS].rect.move(-enemy2.movementSpeed - 2, 0);
								}
								if (shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 250 && abs(Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 20) && abs(shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
								{
									shooterArray[counterS].shooterCanMoveLeft = false;
									if (shooterArray[counterS].enterShooterArrive == true)
									{
										shooterArray[counterS].timeShooterArrive = int(timerlevel1);
										shooterArray[counterS].enterShooterArrive = false;
										shooterArray[counterS].shooterAngry = true;
										Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
									}
									if ((int(timerlevel1) - shooterArray[counterS].timeShooterArrive) % 1 == 0 && shooterArray[counterS].shooterAngry == true)
									{
										shooterArray[counterS].enterShooterAttack = true;
										shooterArray[counterS].shooterAngry = false;
									}
									if (shooterArray[counterS].enterShooterAttack == true)
									{
										projectile2.shooterPlasma = true;
										projectile2.movementSpeed = 7;
										projectile2.direction = 3;
										projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
										plasmaArray.push_back(projectile2);
										soundplasma.play();
										projectile2.shooterPlasma = false;
										Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
										shooterArray[counterS].timeShooterATK = timerlevel1;
										shooterArray[counterS].shooterAngry = false;
										shooterArray[counterS].enterShooterAttack = false;

									}
									shooterArray[counterS].afterShooterArrive = timerlevel1;
									if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 1)
									{
										shooterArray[counterS].shooterAngry = true;
									}

								}
								else
								{
									shooterArray[counterS].shooterCanMoveLeft = true;
									shooterArray[counterS].enterShooterArrive = true;
								}
							}
						}



						if (shooterArray[counterS].tempShooterRand == 1)
						{
							if (Player1.sprite.getPosition().x > shooterArray[counterS].rect.getPosition().x)
							{
								drawPlayerBeforeEnemy = false;
								if (shooterArray[counterS].shooterCanMoveRight == true)
								{
									shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 192, 96, 96));
									if (Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 10)
									{
										shooterArray[counterS].rect.move(1, 0);
									}
									else
									{
										shooterArray[counterS].rect.move(enemy2.movementSpeed + 2, 0);
									}

									shooterArray[counterS].enterShooterArrive = true;
								}
								if (Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 250 && abs(Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 20) && abs(shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
								{
									shooterArray[counterS].shooterCanMoveRight = false;

									if (shooterArray[counterS].enterShooterArrive == true)
									{
										shooterArray[counterS].timeShooterArrive = int(timerlevel1);
										shooterArray[counterS].enterShooterArrive = false;
										shooterArray[counterS].shooterAngry = true;
										Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
									}
									if ((int(timerlevel1) - shooterArray[counterS].timeShooterArrive) % 1 == 0 && shooterArray[counterS].shooterAngry == true)
									{
										shooterArray[counterS].enterShooterAttack = true;
										shooterArray[counterS].shooterAngry = false;
									}
									if (shooterArray[counterS].enterShooterAttack == true)
									{
										projectile2.shooterPlasma = true;
										projectile2.movementSpeed = 7;
										projectile2.direction = 4;
										projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
										plasmaArray.push_back(projectile2);
										soundplasma.play();
										projectile2.shooterPlasma = false;
										Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
										shooterArray[counterS].timeShooterATK = timerlevel1;
										shooterArray[counterS].shooterAngry = false;
										shooterArray[counterS].enterShooterAttack = false;
									}
									shooterArray[counterS].afterShooterArrive = timerlevel1;
									if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 1)
									{
										shooterArray[counterS].shooterAngry = true;
									}
								}
								else
								{
									shooterArray[counterS].shooterCanMoveRight = true;
									shooterArray[counterS].enterShooterArrive = true;
								}
							}
							else if (Player1.sprite.getPosition().x < shooterArray[counterS].rect.getPosition().x)
							{
								drawPlayerBeforeEnemy = false;
								if (shooterArray[counterS].shooterCanMoveLeft == true)
								{
									shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 288, 96, 96));
									if (Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 10)
									{
										shooterArray[counterS].rect.move(-1, 0);
									}
									else
									{
										shooterArray[counterS].rect.move(-enemy2.movementSpeed - 2, 0);
									}
								}
								if (shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 250 && abs(Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 20) && abs(shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
								{
									shooterArray[counterS].shooterCanMoveLeft = false;
									if (shooterArray[counterS].enterShooterArrive == true)
									{
										shooterArray[counterS].timeShooterArrive = int(timerlevel1);
										shooterArray[counterS].enterShooterArrive = false;
										shooterArray[counterS].shooterAngry = true;
										Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
									}
									if ((int(timerlevel1) - shooterArray[counterS].timeShooterArrive) % 1 == 0 && shooterArray[counterS].shooterAngry == true)
									{
										shooterArray[counterS].enterShooterAttack = true;
										shooterArray[counterS].shooterAngry = false;
									}
									if (shooterArray[counterS].enterShooterAttack == true)
									{
										projectile2.shooterPlasma = true;
										projectile2.movementSpeed = 7;
										projectile2.direction = 3;
										projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
										plasmaArray.push_back(projectile2);
										soundplasma.play();
										projectile2.shooterPlasma = false;
										Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
										shooterArray[counterS].timeShooterATK = timerlevel1;
										shooterArray[counterS].shooterAngry = false;
										shooterArray[counterS].enterShooterAttack = false;
									}
									shooterArray[counterS].afterShooterArrive = timerlevel1;
									if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 1)
									{
										shooterArray[counterS].shooterAngry = true;
									}

								}
								else
								{
									shooterArray[counterS].shooterCanMoveLeft = true;
									shooterArray[counterS].enterShooterArrive = true;
								}
							}

							else if (Player1.sprite.getPosition().y < shooterArray[counterS].rect.getPosition().y)
							{
								drawPlayerBeforeEnemy = true;
								if (shooterArray[counterS].shooterCanMoveUp == true)
								{
									shooterArray[counterS].sprite.setTextureRect(sf::IntRect(0, 96, 96, 96));

									if (shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 10)
									{
										shooterArray[counterS].rect.move(0, -1);;
									}
									else
									{
										shooterArray[counterS].rect.move(0, -enemy2.movementSpeed - 2);
									}
								}
								if (shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 250 && abs(Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 40) && abs(shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
								{
									shooterArray[counterS].shooterCanMoveUp = false;
									if (shooterArray[counterS].enterShooterArrive == true)
									{
										shooterArray[counterS].timeShooterArrive = int(timerlevel1);
										shooterArray[counterS].enterShooterArrive = false;
										shooterArray[counterS].shooterAngry = true;
										Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
									}
									if ((int(timerlevel1) - shooterArray[counterS].timeShooterArrive) % 2 == 0 && shooterArray[counterS].shooterAngry == true)
									{
										shooterArray[counterS].enterShooterAttack = true;
										shooterArray[counterS].shooterAngry = false;
									}
									if (shooterArray[counterS].enterShooterAttack == true)
									{
										projectile2.shooterPlasma = true;
										projectile2.movementSpeed = 7;
										projectile2.direction = 1;
										projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
										plasmaArray.push_back(projectile2);
										soundplasma.play();
										projectile2.shooterPlasma = false;
										Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
										shooterArray[counterS].timeShooterATK = timerlevel1;
										shooterArray[counterS].shooterAngry = false;
										shooterArray[counterS].enterShooterAttack = false;

									}
									shooterArray[counterS].afterShooterArrive = timerlevel1;
									if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 2)
									{
										shooterArray[counterS].shooterAngry = true;
									}

								}
								else
								{
									shooterArray[counterS].shooterCanMoveUp = true;
									shooterArray[counterS].enterShooterArrive = true;
								}
							}
							else if (Player1.sprite.getPosition().y > shooterArray[counterS].rect.getPosition().y)
							{
								drawPlayerBeforeEnemy = false;
								if (shooterArray[counterS].shooterCanMoveDown == true)
								{
									shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 0, 96, 96));
									if (Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 10)
									{
										shooterArray[counterS].rect.move(0, 1);
									}
									else
									{
										shooterArray[counterS].rect.move(0, enemy2.movementSpeed + 2);
									}
								}
								if (Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 250 && abs(Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x) < 40 && abs(shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
								{
									if (shooterArray[counterS].enterShooterArrive == true)
									{
										shooterArray[counterS].timeShooterArrive = int(timerlevel1);
										shooterArray[counterS].enterShooterArrive = false;
										shooterArray[counterS].shooterAngry = true;
										Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
									}
									if ((int(timerlevel1) - shooterArray[counterS].timeShooterArrive) % 2 == 0 && shooterArray[counterS].shooterAngry == true)
									{
										shooterArray[counterS].enterShooterAttack = true;
										shooterArray[counterS].shooterAngry = false;
									}
									if (shooterArray[counterS].enterShooterAttack == true)
									{
										projectile2.shooterPlasma = true;
										projectile2.movementSpeed = 7;
										projectile2.direction = 2;
										projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
										plasmaArray.push_back(projectile2);
										soundplasma.play();
										projectile2.shooterPlasma = false;
										Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
										shooterArray[counterS].timeShooterATK = timerlevel1;
										shooterArray[counterS].shooterAngry = false;
										shooterArray[counterS].enterShooterAttack = false;
									}
									shooterArray[counterS].afterShooterArrive = timerlevel1;
									if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 2)
									{
										shooterArray[counterS].shooterAngry = true;
									}
								}
								else
								{
									shooterArray[counterS].shooterCanMoveDown = true;
									shooterArray[counterS].enterShooterArrive = true;
								}
							}
						}
					}
					counterS++;
				}
				

				// Shooter's Plasma Collide with Player
				counter = 0;
				for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
				{
					if (plasmaArray[counter].shooterPlasma == true)
					{
						if (Collision::PixelPerfectTest(plasmaArray[counter].sprite,Player1.sprite))
						{
							soundhit.play();
							Player1.blood = Player1.blood - 3;
							plasmaArray[counter].destroy = true;
						}
					}
					counter++;
				}


			// Spawn Monster
			if (int(timerlevel1) == monsterSpawnTime && int(timerlevel1) != 0)
			{
				enemy1.rect.setPosition(rand() % 1800, rand() % 900);
				enemy1HP.sprite.setPosition(monsterArray[counter].sprite.getPosition().x, monsterArray[counter].sprite.getPosition().y - 20);
				HPmonsterArray.push_back(enemy1HP);
				monsterArray.push_back(enemy1);
				monsterSpawnTime = monsterSpawnTime + 2;
			}

			// Spawn Shooter
			if (int(timerlevel1) == shooterSpawnTime && int(timerlevel1) != 0)
			{
				enemy2.rect.setPosition(rand() % 1800, rand() % 900);
				enemy2HP.sprite.setPosition(shooterArray[counter].sprite.getPosition().x, shooterArray[counter].sprite.getPosition().y - 20);
				HPshooterArray.push_back(enemy2HP);
				shooterArray.push_back(enemy2);
				shooterSpawnTime = shooterSpawnTime + 5;
			}


           // Player Attack Monster
			counter2 = 0;
			for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
			{
				if (Collision::PixelPerfectTest(Player1.sprite, monsterArray[counter2].sprite) && keyspace == 1)
				{
					enterAttack = true;
					if (enterAttack == true)
					{
						monsterArray[counter2].blood = monsterArray[counter2].blood - (Player1.attackDamage - 1);
						HPmonsterArray[counter2].sprite.setTextureRect(sf::IntRect(0, 0,(96* monsterArray[counter2].blood)/10, 96));
						if (monsterArray[counter2].blood <= 0)
						{
							monsterArray[counter2].alive = false;
							HPmonsterArray[counter2].alive = false;
							soundkill.play();
							score += 1000;
							_itoa_s(score, bufferScore, 10);
						}
						enterAttack = false;
					}
					keyspace = 0;
				}
				counter2++;
			}

			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				counter2 = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					if (Collision::PixelPerfectTest(projectileArray[counter].sprite, monsterArray[counter2].sprite))
					{
						soundbomb.play();
						projectileArray[counter].destroy = true;
						monsterArray[counter2].blood = monsterArray[counter2].blood - projectileArray[counter].attackDamage;
						HPmonsterArray[counter2].sprite.setTextureRect(sf::IntRect(0, 0, (96 * monsterArray[counter2].blood) / 10, 96));
						if (monsterArray[counter2].blood <= 0)
						{
							monsterArray[counter2].alive = false;
							HPmonsterArray[counter2].alive = false;
							soundkill.play();
							score += 100;
							_itoa_s(score, bufferScore, 10);
						}
					}
					counter2++;
				}
				counter++;
			}

			// Player Attack Shooter
			counter2 = 0;
			for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
			{
				if (Collision::PixelPerfectTest(Player1.sprite, shooterArray[counter2].sprite) && keyspace == 1)
				{
					enterAttack = true;
					if (enterAttack == true)
					{
						shooterArray[counter2].blood = shooterArray[counter2].blood - Player1.attackDamage;
						HPshooterArray[counter2].sprite.setTextureRect(sf::IntRect(0, 0, (96 * shooterArray[counter2].blood) / 10, 96));
						if (shooterArray[counter2].blood <= 0)
						{
							shooterArray[counter2].alive = false;
							HPshooterArray[counter2].alive = false;
							soundbomb.play();
							score += 500;
							_itoa_s(score, bufferScore, 10);
						}
						enterAttack = false;
					}
					keyspace = 0;
				}
				counter2++;
			}

			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				counter2 = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					if (Collision::PixelPerfectTest(projectileArray[counter].sprite, shooterArray[counter2].sprite))
					{
						soundbomb.play();
						projectileArray[counter].destroy = true;
						shooterArray[counter2].blood = shooterArray[counter2].blood - projectileArray[counter].attackDamage;
						HPshooterArray[counter2].sprite.setTextureRect(sf::IntRect(0, 0, (96 * shooterArray[counter2].blood) / 10, 96));
						if (shooterArray[counter2].blood <= 0)
						{
							shooterArray[counter2].alive = false;
							HPshooterArray[counter2].alive = false;
							soundbomb.play();
							score += 1500;
							_itoa_s(score, bufferScore, 10);
						}
					}
					counter2++;
				}
				counter++;
			}

			

			// Draw Bullet
			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				if (projectileArray[counter].sprite.getPosition().x < 0 || projectileArray[counter].sprite.getPosition().x > 1850 || projectileArray[counter].sprite.getPosition().y < 0 || projectileArray[counter].sprite.getPosition().y > 1000)
				{
					projectileArray[counter].destroy = true;
				}
				projectileArray[counter].update();
				window.draw(projectileArray[counter].sprite);
				counter++;
			}

			// Draw Plasma
			counter = 0;
			for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
			{
				if (plasmaArray[counter].sprite.getPosition().x < 0 || plasmaArray[counter].sprite.getPosition().x > 1850 || plasmaArray[counter].sprite.getPosition().y < 0 || plasmaArray[counter].sprite.getPosition().y > 1000)
				{
					plasmaArray[counter].destroy = true;
				}
				plasmaArray[counter].update();
				window.draw(plasmaArray[counter].sprite);
				counter++;
			}

			// Fire Bullet
			if (keyC == 1 && powerBullet == true)
			{
				soundshoot.play();
				projectileArray.push_back(projectile1);
				keyC = 0;
			}

			// Check Direction Bullet
			projectile1.direction = Player1.checkDirection;
			if (projectile1.direction == 1)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 128, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}
			
				projectile1.sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x - 60, Player1.sprite.getPosition().y - 80);
				
			}
			if (projectile1.direction == 2)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}

				projectile1.sprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x - 5, Player1.sprite.getPosition().y - 40);
			}
			if (projectile1.direction == 3)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 384, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}

				projectile1.sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x - 95, Player1.sprite.getPosition().y - 60);
			}
			if (projectile1.direction == 4)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 256, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}

				projectile1.sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x + 15, Player1.sprite.getPosition().y - 60);
			}

	
			// Gold Coin
			if (int(timerlevel1) % 5 == 0 && enterCoin == 0 && int(timerlevel1) != 0)
			{
				enterCoin = 1;
				spriteGoldCoin.setTextureRect(sf::IntRect(0, 0, 80, 80));
				goldCoinpx = rand() % 1800;
				goldCoinpy = rand() % 900;

			}
			if (enterCoin == 1)
			{
				spriteGoldCoin.setPosition(goldCoinpx, goldCoinpy);
				window.draw(spriteGoldCoin);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteGoldCoin))
			{
				soundcoin.play();
				spriteGoldCoin.setTextureRect(sf::IntRect(0, 0, 0, 0));
				score = score + 100;
				_itoa_s(score, bufferScore, 10);
				enterCoin = 0;
			}

			// Silver Coin
			if (int(timerlevel1) % 3 == 0 && enterSilverCoin == 0 && int(timerlevel1) != 0)
			{
				enterSilverCoin = 1;
				spriteSilverCoin.setTextureRect(sf::IntRect(0, 0, 96, 96));
				silverCoinpx = rand() % 1800;
				silverCoinpy = rand() % 900;

			}
			if (enterSilverCoin == 1)
			{
				spriteSilverCoin.setPosition(silverCoinpx, silverCoinpy);
				window.draw(spriteSilverCoin);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteSilverCoin))
			{
				soundcoin.play();
				spriteSilverCoin.setTextureRect(sf::IntRect(0, 0, 0, 0));
				score = score + 50;
				_itoa_s(score, bufferScore, 10);
				enterSilverCoin = 0;
			}

			// Bronze Coin
			if (int(timerlevel1) % 1 == 0 && enterBronzeCoin == 0 && int(timerlevel1) != 0)
			{
				enterBronzeCoin = 1;
				spriteBronzeCoin.setTextureRect(sf::IntRect(0, 0, 96, 96));
				bronzeCoinpx = rand() % 1800;
				bronzeCoinpy = rand() % 900;

			}
			if (enterBronzeCoin == 1)
			{
				spriteBronzeCoin.setPosition(bronzeCoinpx, bronzeCoinpy);
				window.draw(spriteBronzeCoin);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteBronzeCoin))
			{
				soundcoin.play();
				spriteBronzeCoin.setTextureRect(sf::IntRect(0, 0, 0, 0));
				score = score + 10;
				_itoa_s(score, bufferScore, 10);
				enterBronzeCoin = 0;
			}

			// Aid
			if (int(timerlevel1) % 30 == 0 && enterAid == 0 && int(timerlevel1) != 0)
			{
				enterAid = 1;
				spriteAid.setTextureRect(sf::IntRect(0, 0, 80, 80));
				aidpx = rand() % 1800;
				aidpy = rand() % 900;

			}
			if (enterAid == 1)
			{
				spriteAid.setPosition(aidpx, aidpy);
				window.draw(spriteAid);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteAid))
			{
				soundaidcoin.play();
				spriteAid.setTextureRect(sf::IntRect(0, 0, 0, 0));
				Player1.blood = Player1.blood + 20;
				if (Player1.blood > 100)
				{
					Player1.blood = 100;
				}
				enterAid = 0;
			}

			// Gun
			if (int(timerlevel1) % 20 == 0 && enterGun == 0 && int(timerlevel1) != 0)
			{
				enterGun = 1;
				spriteGun.setTextureRect(sf::IntRect(0, 0, 80, 80));
				gunpx = rand() % 1800;
				gunpy = rand() % 900;

			}
			if (enterGun == 1)
			{
				spriteGun.setPosition(gunpx, gunpy);
				window.draw(spriteGun);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteGun))
			{
				soundguncoin.play();
				spriteGun.setTextureRect(sf::IntRect(0, 0, 0, 0));
				powerBullet = true;
				getBullet = int(timerlevel1);
				enterGun = 0;
			}

			if (int(timerlevel1) - getBullet > 5)
			{
				powerBullet = false;
			}


			// text score
			window.draw(textscore);
			textscore.setPosition(Player1.sprite.getPosition().x - 600, Player1.sprite.getPosition().y - 320);
			textscore.setString("score : ");

			// text point
			window.draw(textpoint);
			textpoint.setPosition(Player1.sprite.getPosition().x - 450, Player1.sprite.getPosition().y - 320);
			textpoint.setString(bufferScore);
			if (score == 0)
			{
				_itoa_s(score, bufferScore, 10);
			}

			// text time
			window.draw(textTimeLevel1);
			textTimeLevel1.setPosition(Player1.sprite.getPosition().x, Player1.sprite.getPosition().y - 320);
			textTimeLevel1.setString(bufferTimeLevel1);

			// text health
			window.draw(textHealth);
			textHealth.setPosition(Player1.sprite.getPosition().x + 130, Player1.sprite.getPosition().y - 320);
			textHealth.setString(bufferHealth);
			_itoa_s(Player1.blood, bufferHealth, 10);


			// draw HP bar
			window.draw(spriteHPb);
			window.draw(spriteHPr);
			spriteHPr.setTextureRect(sf::IntRect(0, 0, Player1.blood, 40));
			spriteHPr.setPosition(Player1.sprite.getPosition().x + 195, Player1.sprite.getPosition().y - 320);

			spriteHPb.setTextureRect(sf::IntRect(0, 0, 100, 10));
			spriteHPb.setPosition(Player1.sprite.getPosition().x + 195, Player1.sprite.getPosition().y - 320);

			// Win
			if (int(timerlevel1) == 150)
			{
				counterM = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					monsterArray[counterM].alive = false;
					HPmonsterArray[counterM].alive = false;
					counterM++;
				}

				counterS = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					shooterArray[counterS].alive = false;
					HPshooterArray[counterS].alive = false;
					counterS++;
				}

				counterL = 0;
				for (iterLavar = lavarArray.begin(); iterLavar != lavarArray.end(); iterLavar++)
				{
					lavarArray[counterL].alive = false;
					HPlavarArray[counterL].alive = false;
					counterL++;
				}

				counterP = 0;
				for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
				{
					plasmaArray[counterP].destroy = true;
					counterP++;
				}

				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					projectileArray[counter].destroy = true;
					counter++;
				}
				formLevel1 = false;
				loadingScene2 = true;
				restartTimeLoadingScene2 = true;
			}

			// Lose
			if (Player1.blood <= 0)
			{
				counterM = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					monsterArray[counterM].alive = false;
					HPmonsterArray[counterM].alive = false;
					counterM++;
				}

				counterS = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					shooterArray[counterS].alive = false;
					HPshooterArray[counterS].alive = false;
					counterS++;
				}

				counterL = 0;
				for (iterLavar = lavarArray.begin(); iterLavar != lavarArray.end(); iterLavar++)
				{
					lavarArray[counterL].alive = false;
					HPlavarArray[counterL].alive = false;
					counterL++;
				}

				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					projectileArray[counter].destroy = true;
					counter++;
				}

				counterP = 0;
				for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
				{
					plasmaArray[counterP].destroy = true;
					counterP++;
				}

				// Deleted Death Monsters
				counter = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					if (monsterArray[counter].alive == false)
					{
						monsterArray.erase(iterMonster);
						break;
					}
					counter++;
				}

				counter = 0;
				for (iterHPMonster = HPmonsterArray.begin(); iterHPMonster != HPmonsterArray.end(); iterHPMonster++)
				{
					if (HPmonsterArray[counter].alive == false)
					{
						HPmonsterArray.erase(iterHPMonster);
						break;
					}
					counter++;
				}

				// Deleted Death Shooter
				counter = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					if (shooterArray[counter].alive == false)
					{
						shooterArray.erase(iterShooter);
						break;
					}
					counter++;
				}

				counter = 0;
				for (iterHPshooter = HPshooterArray.begin(); iterHPshooter != HPshooterArray.end(); iterHPshooter++)
				{
					if (HPshooterArray[counter].alive == false)
					{
						HPshooterArray.erase(iterHPshooter);
						break;
					}
					counter++;
				}

				// Delete Bullet
				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					if (projectileArray[counter].destroy == true)
					{
						projectileArray.erase(iter);
						break;
					}
					counter++;
				}

				// Delete Plasma
				counter = 0;
				for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
				{
					if (plasmaArray[counter].destroy == true)
					{
						plasmaArray.erase(iterPlasma);
						break;
					}
					counter++;
				}
				level = 999;
				musicStage1.stop();
				soundGameOver = true;
				formLevel1 = true;
			}

			if (goExit == true)
			{
				musicMenu.stop();
				musicStage1.stop();
				musicStage2.stop();
				musicStage3.stop();
				Player1.blood = 100;
				Player1.attackDamage = 5;
				monsterSpawnTime = 5;
				shooterSpawnTime = 10;
				lavarSpawnTime = 20;
				enemy1.movementSpeed = 1;
				enemy2.movementSpeed = 1;
				enemy3.movementSpeed = 1;
				restarttimelevel0 = 1;
				restarttimelevel1 = 1;
				restarttimelevel2 = 1;
				restarttimelevel3 = 1;
				timerlevel1 = 0;
				timerlevel2 = 0;
				timerlevel3 = 0;
				restartTimeLoadingScene = true;
				restartTimeLoadingScene2 = true;
				restartTimeLoadingScene3 = true;
				powerBullet = false;
				pause = false;
				play = false;
				score = 0;
				
				sf::View view2(sf::FloatRect(200, 200, 300, 200));
				view2.setSize(sf::Vector2f(1920, 1080));
				view2.setCenter(sf::Vector2f(view2.getSize().x / 2, view2.getSize().y / 2));
				window.setView(view2);
				level = 0;
				goExit = false;
			}

			// Deleted Death Monsters
			counter = 0;
			for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
			{
				if (monsterArray[counter].alive == false)
				{
					monsterArray.erase(iterMonster);
					break;
				}
				counter++;
			}

			counter = 0;
			for (iterHPMonster = HPmonsterArray.begin(); iterHPMonster != HPmonsterArray.end(); iterHPMonster++)
			{
				if (HPmonsterArray[counter].alive == false)
				{
					HPmonsterArray.erase(iterHPMonster);
					break;
				}
				counter++;
			}

			// Deleted Death Shooter
			counter = 0;
			for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
			{
				if (shooterArray[counter].alive == false)
				{
					shooterArray.erase(iterShooter);
					break;
				}
				counter++;
			}

			counter = 0;
			for (iterHPshooter = HPshooterArray.begin(); iterHPshooter != HPshooterArray.end(); iterHPshooter++)
			{
				if (HPshooterArray[counter].alive == false)
				{
					HPshooterArray.erase(iterHPshooter);
					break;
				}
				counter++;
			}

			// Delete Bullet
			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				if (projectileArray[counter].destroy == true)
				{
					projectileArray.erase(iter);
					break;
				}
				counter++;
			}

			// Delete Plasma
			counter = 0;
			for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
			{
				if (plasmaArray[counter].destroy == true)
				{
					plasmaArray.erase(iterPlasma);
					break;
				}
				counter++;
			}
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (loadingScene2 == true)
		{
			if (restartTimeLoadingScene2 == true)
			{
				clock.restart();
				restartTimeLoadingScene2 = false;
			}
			timerLoadingScene2 = clock.getElapsedTime().asSeconds();
			if (timerLoadingScene2 < 5.00)
			{
				
				sf::View view2(sf::FloatRect(200, 200, 300, 200));
				view2.setSize(sf::Vector2f(1920, 1080));
				view2.setCenter(sf::Vector2f(view2.getSize().x / 2, view2.getSize().y / 2));
				window.setView(view2);
				window.draw(spriteLoadingSceneLevel2);
				Player1.sprite.setPosition(960, 540);
				Player1.attackDamage = 3;
				enemy1.attackDamage = 5;
				enemy1.blood = 15;
				enemy1.movementSpeed = 3;
				enemy2.attackDamage = 7;
				enemy2.movementSpeed = 4;
				enemy3.blood = 20;
				monsterSpawnTime = 5;
				shooterSpawnTime = 10;
				lavarSpawnTime = 20;
				Player1.blood = 100;
				
			}
			else
			{
				level = 2;
			}
		}
		
		
		
		
		
		
		if (level == 2)
		{
			formLevel2 = true;
			loadingScene2 = false;
			if (restarttimelevel2 == 1)
			{
				clock.restart();
				musicStage1.stop();
				musicStage2.play();
				restarttimelevel2 = 0;
			}

			// timer 
			timerlevel2milli = clock.getElapsedTime().asMilliseconds();
			if (pause == false)
			{
				gtime2 = ctime2;
				ctime2 = clock.getElapsedTime().asSeconds();
				if (gtime2 != ctime2)
				{
					enterTimeLevel2 = true;
				}

				if (ctime2 % 1 == 0 && enterTimeLevel2 == true)
				{
					if (pause == false)
					{
						timerlevel2++;
					}
					enterTimeLevel2 = false;
				}
			}

			// Pause
			if (pause == true)
			{
				if (play == true)
				{
					pause = false;
					play = false;
				}
			}


			if (int(timerlevel2) % 1 == 0 && enterTime2 == 1)
			{
				nowtimelevel2 = timerlevel2;
				_itoa_s(int(timerlevel2), bufferTimeLevel2, 10);
				enterTime2 = 0;
			}
			aftercounttimelevel2 = timerlevel2;
			if (aftercounttimelevel2 - nowtimelevel2 >= 1)
			{
				enterTime2 = 1;
			}

			//view
			window.setView(view1);


			// player sword attack
			if (keyspace == 1)
			{
				deltatimeplayerattacksword = timerlevel2milli - playerattackswordtime;
				if (deltatimeplayerattacksword < 150)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 640, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 512, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 768, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 896, 128, 128));
					}
				}
				if (deltatimeplayerattacksword >= 150 && deltatimeplayerattacksword < 300)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 640, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 512, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 768, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 896, 128, 128));
					}
				}
				if (deltatimeplayerattacksword >= 300 && deltatimeplayerattacksword < 450)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 640, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 512, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 768, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 896, 128, 128));
					}
				}
				if (deltatimeplayerattacksword > 450)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 128, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 256, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 384, 128, 128));
					}
					keyspace = 0;
				}
			}


			window.clear();
			window.draw(spriteLevel2BehideBackground);
			window.draw(spriteLevel2Background);




			if (drawPlayerBeforeEnemy == true)
			{
				// Draw Player
				window.draw(Player1.sprite);
				window.draw(spriteShoulderCannon);


				// Draw Monster
				counter = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					monsterArray[counter].update();
					enemy1.rect.setPosition(generateRandom(1920), generateRandom(1080));
					window.draw(monsterArray[counter].sprite);
					counter++;
				}

				// Draw Shooter
				counterShooter = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					shooterArray[counterShooter].update();
					enemy2.rect.setPosition(rand() % 1800, rand() % 900);
					window.draw(shooterArray[counterShooter].sprite);
					counterShooter++;
				}

				// Draw Lavar
				counterLavar = 0;
				for (iterLavar = lavarArray.begin(); iterLavar != lavarArray.end(); iterLavar++)
				{
					lavarArray[counterLavar].update();
					enemy3.rect.setPosition(rand() % 1800, rand() % 900);
					window.draw(lavarArray[counterLavar].sprite);
					counterLavar++;
				}
			}

			if (drawPlayerBeforeEnemy == false)
			{
				// Draw Monster

				counter = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					monsterArray[counter].update();
					enemy1.rect.setPosition(generateRandom(1920), generateRandom(1080));
					window.draw(monsterArray[counter].sprite);
					counter++;
				}

				// Draw Shooter

				counterShooter = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					shooterArray[counterShooter].update();
					enemy2.rect.setPosition(rand() % 1800, rand() % 900);
					window.draw(shooterArray[counterShooter].sprite);
					counterShooter++;
				}

				// Draw Lavar
				counterLavar = 0;
				for (iterLavar = lavarArray.begin(); iterLavar != lavarArray.end(); iterLavar++)
				{
					lavarArray[counterLavar].update();
					enemy3.rect.setPosition(rand() % 1800, rand() % 900);
					window.draw(lavarArray[counterLavar].sprite);
					counterLavar++;
				}

				window.draw(Player1.sprite);
				window.draw(spriteShoulderCannon);
			}

			// Draw HP Monster
			counter = 0;
			for (iterHPMonster = HPmonsterArray.begin(); iterHPMonster != HPmonsterArray.end(); iterHPMonster++)
			{
				HPmonsterArray[counter].update();
				HPmonsterArray[counter].sprite.setPosition(monsterArray[counter].sprite.getPosition().x, monsterArray[counter].sprite.getPosition().y - 20);
				window.draw(HPmonsterArray[counter].sprite);
				counter++;
			}

			// Draw HP Shooter
			counter = 0;
			for (iterHPshooter = HPshooterArray.begin(); iterHPshooter != HPshooterArray.end(); iterHPshooter++)
			{
				HPshooterArray[counter].update();
				HPshooterArray[counter].sprite.setPosition(shooterArray[counter].sprite.getPosition().x, shooterArray[counter].sprite.getPosition().y - 20);
				window.draw(HPshooterArray[counter].sprite);
				counter++;
			}

			// Draw HP Lavar
			counter = 0;
			for (iterHPLavar = HPlavarArray.begin(); iterHPLavar != HPlavarArray.end(); iterHPLavar++)
			{
				HPlavarArray[counter].update();
				HPlavarArray[counter].sprite.setPosition(lavarArray[counter].sprite.getPosition().x, lavarArray[counter].sprite.getPosition().y - 20);
				window.draw(HPlavarArray[counter].sprite);
				counter++;
			}

			// Update Player
			Player1.update();
			Player1.updateMovement();


			// Player View
			window.setView(view1);
			view1.setCenter(Player1.sprite.getPosition());

			// Delete All Enemy
			if (goExit == true || loadingScene3 == true)
			{
				counterM = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					monsterArray[counterM].alive = false;
					HPmonsterArray[counterM].alive = false;
					counterM++;
				}

				counterS = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					shooterArray[counterS].alive = false;
					HPshooterArray[counterS].alive = false;
					counterS++;
				}

				counterL = 0;
				for (iterLavar = lavarArray.begin(); iterLavar != lavarArray.end(); iterLavar++)
				{
					lavarArray[counterL].alive = false;
					HPlavarArray[counterL].alive = false;
					counterL++;
				}

				counterP = 0;
				for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
				{
					plasmaArray[counterP].destroy = true;
					counterP++;
				}

				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					projectileArray[counter].destroy = true;
					counter++;
				}
			}


			// Monster Chase And Attack
			counterM = 0;
			for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
			{
				timerMonster = clock.getElapsedTime().asMilliseconds();
				if (timerMonster % 50 == 0)
				{
					monsterArray[counterM].tempMonsterRand = rand() % 2;
				}
				if (monsterArray[counterM].tempMonsterRand == 0)
				{
					if (Player1.sprite.getPosition().y < monsterArray[counterM].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = true;
						if (int(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
						{
							monsterArray[counterM].counterWalkingMonster++;
						}
						if (monsterArray[counterM].monsterCanMoveUp == true)
						{
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 96, 96, 96));

							if (monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 10)
							{
								monsterArray[counterM].rect.move(0, -1);;
							}
							else
							{
								monsterArray[counterM].rect.move(0, -enemy1.movementSpeed);
							}
						}
						if (monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x < 40) && abs(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							monsterArray[counterM].monsterCanMoveUp = false;
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 672, 96, 96));
							monsterArray[counterM].counterMonsterAttack++;
							if (monsterArray[counterM].enterMonsterArrive == true)
							{
								monsterArray[counterM].timeMonsterArrive = int(timerlevel2);
								monsterArray[counterM].enterMonsterArrive = false;
								monsterArray[counterM].monsterAngry = true;
								Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
							}
							if ((int(timerlevel2) - monsterArray[counterM].timeMonsterArrive) % 2 == 0 && monsterArray[counterM].monsterAngry == true)
							{
								monsterArray[counterM].enterMonsterAttack = true;
								monsterArray[counterM].monsterAngry = false;
							}
							if (monsterArray[counterM].enterMonsterAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
								monsterArray[counterM].timeMonsterATK = timerlevel2;
								monsterArray[counterM].monsterAngry = false;
								monsterArray[counterM].enterMonsterAttack = false;

							}
							monsterArray[counterM].afterMonsterArrive = timerlevel2;
							if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 2)
							{
								monsterArray[counterM].monsterAngry = true;
							}

						}
						else
						{
							monsterArray[counterM].monsterCanMoveUp = true;
							monsterArray[counterM].enterMonsterArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().y > monsterArray[counterM].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = false;
						if (int(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
						{
							monsterArray[counterM].counterWalkingMonster++;
						}
						if (monsterArray[counterM].monsterCanMoveDown == true)
						{
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 0, 96, 96));
							if (Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 10)
							{
								monsterArray[counterM].rect.move(0, 1);
							}
							else
							{
								monsterArray[counterM].rect.move(0, enemy1.movementSpeed);
							}
						}
						if (Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x) < 40 && abs(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							monsterArray[counterM].monsterCanMoveDown = false;
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 576, 96, 96));
							monsterArray[counterM].counterMonsterAttack++;
							if (monsterArray[counterM].enterMonsterArrive == true)
							{
								monsterArray[counterM].timeMonsterArrive = int(timerlevel2);
								monsterArray[counterM].enterMonsterArrive = false;
								monsterArray[counterM].monsterAngry = true;
								Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
							}
							if ((int(timerlevel2) - monsterArray[counterM].timeMonsterArrive) % 2 == 0 && monsterArray[counterM].monsterAngry == true)
							{
								monsterArray[counterM].enterMonsterAttack = true;
								monsterArray[counterM].monsterAngry = false;
							}
							if (monsterArray[counterM].enterMonsterAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
								monsterArray[counterM].timeMonsterATK = timerlevel2;
								monsterArray[counterM].monsterAngry = false;
								monsterArray[counterM].enterMonsterAttack = false;

							}
							monsterArray[counterM].afterMonsterArrive = timerlevel2;
							if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 2)
							{
								monsterArray[counterM].monsterAngry = true;
							}

						}
						else
						{
							monsterArray[counterM].monsterCanMoveDown = true;
							monsterArray[counterM].enterMonsterArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().x > monsterArray[counterM].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (int(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x) % 5 == 0)
						{
							monsterArray[counterM].counterWalkingMonster++;
						}
						if (monsterArray[counterM].monsterCanMoveRight == true)
						{
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 288, 96, 96));
							monsterArray[counterM].rect.move(enemy1.movementSpeed, 0);
							monsterArray[counterM].enterMonsterArrive = true;
						}
						if (Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 20) && abs(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							monsterArray[counterM].monsterCanMoveRight = false;
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 480, 96, 96));
							monsterArray[counterM].counterMonsterAttack++;
							if (monsterArray[counterM].enterMonsterArrive == true)
							{
								monsterArray[counterM].timeMonsterArrive = int(timerlevel2);
								monsterArray[counterM].enterMonsterArrive = false;
								monsterArray[counterM].monsterAngry = true;
								Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
							}
							if ((int(timerlevel2) - monsterArray[counterM].timeMonsterArrive) % 1 == 0 && monsterArray[counterM].monsterAngry == true)
							{
								monsterArray[counterM].enterMonsterAttack = true;
								monsterArray[counterM].monsterAngry = false;
							}
							if (monsterArray[counterM].enterMonsterAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
								monsterArray[counterM].timeMonsterATK = timerlevel2;
								monsterArray[counterM].monsterAngry = false;
								monsterArray[counterM].enterMonsterAttack = false;

							}
							monsterArray[counterM].afterMonsterArrive = timerlevel2;
							if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 1)
							{
								monsterArray[counterM].monsterAngry = true;
							}
						}
						else
						{
							monsterArray[counterM].monsterCanMoveRight = true;
							monsterArray[counterM].enterMonsterArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().x < monsterArray[counterM].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (int(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x) % 5 == 0)
						{
							monsterArray[counterM].counterWalkingMonster++;
						}
						if (monsterArray[counterM].monsterCanMoveLeft == true)
						{
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 192, 96, 96));
							monsterArray[counterM].rect.move(-enemy1.movementSpeed, 0);
						}
						if (monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 20) && abs(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							monsterArray[counterM].monsterCanMoveLeft = false;
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 384, 96, 96));
							monsterArray[counterM].counterMonsterAttack++;
							if (monsterArray[counterM].enterMonsterArrive == true)
							{
								monsterArray[counterM].timeMonsterArrive = int(timerlevel2);
								monsterArray[counterM].enterMonsterArrive = false;
								monsterArray[counterM].monsterAngry = true;
								Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
							}
							if ((int(timerlevel2) - monsterArray[counterM].timeMonsterArrive) % 1 == 0 && monsterArray[counterM].monsterAngry == true)
							{
								monsterArray[counterM].enterMonsterAttack = true;
								monsterArray[counterM].monsterAngry = false;
							}
							if (monsterArray[counterM].enterMonsterAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
								monsterArray[counterM].timeMonsterATK = timerlevel2;
								monsterArray[counterM].monsterAngry = false;
								monsterArray[counterM].enterMonsterAttack = false;

							}
							monsterArray[counterM].afterMonsterArrive = timerlevel2;
							if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 1)
							{
								monsterArray[counterM].monsterAngry = true;
							}

						}
						else
						{
							monsterArray[counterM].monsterCanMoveLeft = true;
							monsterArray[counterM].enterMonsterArrive = true;
						}
					}
				}

				if (monsterArray[counterM].tempMonsterRand == 1)
				{
					if (Player1.sprite.getPosition().x > monsterArray[counterM].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if ((int(Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x) % 5 == 0))
						{
							monsterArray[counterM].counterWalkingMonster++;
						}
						if (monsterArray[counterM].monsterCanMoveRight == true)
						{
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 288, 96, 96));
							if (Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x < 10)
							{
								monsterArray[counterM].rect.move(1, 0);;
							}
							else
							{
								monsterArray[counterM].rect.move(enemy1.movementSpeed, 0);
							}
							monsterArray[counterM].enterMonsterArrive = true;
						}
						if (Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 20) && abs(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							monsterArray[counterM].monsterCanMoveRight = false;
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 480, 96, 96));
							monsterArray[counterM].counterMonsterAttack++;

							if (monsterArray[counterM].enterMonsterArrive == true)
							{
								monsterArray[counterM].timeMonsterArrive = int(timerlevel2);
								monsterArray[counterM].enterMonsterArrive = false;
								monsterArray[counterM].monsterAngry = true;
								Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
							}
							if ((int(timerlevel2) - monsterArray[counterM].timeMonsterArrive) % 1 == 0 && monsterArray[counterM].monsterAngry == true)
							{
								monsterArray[counterM].enterMonsterAttack = true;
								monsterArray[counterM].monsterAngry = false;
							}
							if (monsterArray[counterM].enterMonsterAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
								monsterArray[counterM].timeMonsterATK = timerlevel2;
								monsterArray[counterM].monsterAngry = false;
								monsterArray[counterM].enterMonsterAttack = false;

							}
							monsterArray[counterM].afterMonsterArrive = timerlevel2;
							if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 1)
							{
								monsterArray[counterM].monsterAngry = true;
							}
						}
						else
						{
							monsterArray[counterM].monsterCanMoveRight = true;
							monsterArray[counterM].enterMonsterArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().x < monsterArray[counterM].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (int(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x) % 5 == 0)
						{
							monsterArray[counterM].counterWalkingMonster++;
						}
						if (monsterArray[counterM].monsterCanMoveLeft == true)
						{
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 192, 96, 96));
							if (monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 10)
							{
								monsterArray[counterM].rect.move(-1, 0);;
							}
							else
							{
								monsterArray[counterM].rect.move(-enemy1.movementSpeed, 0);
							}
						}
						if (monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 20) && abs(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							monsterArray[counterM].monsterCanMoveLeft = false;
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 384, 96, 96));
							monsterArray[counterM].counterMonsterAttack++;
							if (monsterArray[counterM].enterMonsterArrive == true)
							{
								monsterArray[counterM].timeMonsterArrive = int(timerlevel2);
								monsterArray[counterM].enterMonsterArrive = false;
								monsterArray[counterM].monsterAngry = true;
								Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
							}
							if ((int(timerlevel2) - monsterArray[counterM].timeMonsterArrive) % 1 == 0 && monsterArray[counterM].monsterAngry == true)
							{
								monsterArray[counterM].enterMonsterAttack = true;
								monsterArray[counterM].monsterAngry = false;
							}
							if (monsterArray[counterM].enterMonsterAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
								monsterArray[counterM].timeMonsterATK = timerlevel2;
								monsterArray[counterM].monsterAngry = false;
								monsterArray[counterM].enterMonsterAttack = false;

							}
							monsterArray[counterM].afterMonsterArrive = timerlevel2;
							if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 1)
							{
								monsterArray[counterM].monsterAngry = true;
							}

						}
						else
						{
							monsterArray[counterM].monsterCanMoveLeft = true;
							monsterArray[counterM].enterMonsterArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().y < monsterArray[counterM].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = true;
						if (int(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
						{
							monsterArray[counterM].counterWalkingMonster++;
						}
						if (monsterArray[counterM].monsterCanMoveUp == true)
						{
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 96, 96, 96));

							if (monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 10)
							{
								monsterArray[counterM].rect.move(0, -1);;
							}
							else
							{
								monsterArray[counterM].rect.move(0, -enemy1.movementSpeed);
							}
						}
						if (monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x < 40) && abs(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							monsterArray[counterM].monsterCanMoveUp = false;
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 672, 96, 96));
							monsterArray[counterM].counterMonsterAttack++;
							if (monsterArray[counterM].enterMonsterArrive == true)
							{
								monsterArray[counterM].timeMonsterArrive = int(timerlevel2);
								monsterArray[counterM].enterMonsterArrive = false;
								monsterArray[counterM].monsterAngry = true;
								Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
							}
							if ((int(timerlevel2) - monsterArray[counterM].timeMonsterArrive) % 2 == 0 && monsterArray[counterM].monsterAngry == true)
							{
								monsterArray[counterM].enterMonsterAttack = true;
								monsterArray[counterM].monsterAngry = false;
							}
							if (monsterArray[counterM].enterMonsterAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
								monsterArray[counterM].timeMonsterATK = timerlevel2;
								monsterArray[counterM].monsterAngry = false;
								monsterArray[counterM].enterMonsterAttack = false;

							}
							monsterArray[counterM].afterMonsterArrive = timerlevel2;
							if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 2)
							{
								monsterArray[counterM].monsterAngry = true;
							}

						}
						else
						{
							monsterArray[counterM].monsterCanMoveUp = true;
							monsterArray[counterM].enterMonsterArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().y > monsterArray[counterM].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = false;
						if (int(monsterArray[counterM].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
						{
							monsterArray[counterM].counterWalkingMonster++;
						}
						if (monsterArray[counterM].monsterCanMoveDown == true)
						{
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterWalkingMonster * 96, 0, 96, 96));
							if (Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 10)
							{
								monsterArray[counterM].rect.move(0, 1);
							}
							else
							{
								monsterArray[counterM].rect.move(0, enemy1.movementSpeed);
							}
						}
						if (Player1.sprite.getPosition().y - monsterArray[counterM].rect.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - monsterArray[counterM].rect.getPosition().x) < 40 && abs(monsterArray[counterM].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							monsterArray[counterM].monsterCanMoveDown = false;
							monsterArray[counterM].sprite.setTextureRect(sf::IntRect(monsterArray[counterM].counterMonsterAttack * 96, 576, 96, 96));
							monsterArray[counterM].counterMonsterAttack++;
							if (monsterArray[counterM].enterMonsterArrive == true)
							{
								monsterArray[counterM].timeMonsterArrive = int(timerlevel2);
								monsterArray[counterM].enterMonsterArrive = false;
								monsterArray[counterM].monsterAngry = true;
								Player1.blood = Player1.blood + monsterArray[counterM].attackDamage;
							}
							if ((int(timerlevel2) - monsterArray[counterM].timeMonsterArrive) % 2 == 0 && monsterArray[counterM].monsterAngry == true)
							{
								monsterArray[counterM].enterMonsterAttack = true;
								monsterArray[counterM].monsterAngry = false;
							}
							if (monsterArray[counterM].enterMonsterAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - monsterArray[counterM].attackDamage;
								monsterArray[counterM].timeMonsterATK = timerlevel2;
								monsterArray[counterM].monsterAngry = false;
								monsterArray[counterM].enterMonsterAttack = false;

							}
							monsterArray[counterM].afterMonsterArrive = timerlevel2;
							if (monsterArray[counterM].afterMonsterArrive - monsterArray[counterM].timeMonsterATK >= 2)
							{
								monsterArray[counterM].monsterAngry = true;
							}

						}
						else
						{
							monsterArray[counterM].monsterCanMoveDown = true;
							monsterArray[counterM].enterMonsterArrive = true;
						}
					}
				}


				if (monsterArray[counterM].counterWalkingMonster >= 2)
				{
					monsterArray[counterM].counterWalkingMonster = 0;
				}

				if (monsterArray[counterM].counterMonsterAttack >= 2)
				{
					monsterArray[counterM].counterMonsterAttack = 0;
				}
				counterM++;
			}



			// Shooter Chase And Attack
			counterS = 0;
			for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
			{
				timerShooter = clock.getElapsedTime().asMilliseconds();
				if (timerShooter % 50 == 0)
				{
					shooterArray[counterS].tempShooterRand = rand() % 2;
				}
				if (shooterArray[counterS].tempShooterRand == 0)
				{
					if (Player1.sprite.getPosition().y < shooterArray[counterS].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = true;
						if (shooterArray[counterS].shooterCanMoveUp == true)
						{
							shooterArray[counterS].sprite.setTextureRect(sf::IntRect(0, 96, 96, 96));

							if (shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 10)
							{
								shooterArray[counterS].rect.move(0, -1);;
							}
							else
							{
								shooterArray[counterS].rect.move(0, -enemy2.movementSpeed);
							}
						}
						if (shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 250 && abs(Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 40) && abs(shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							shooterArray[counterS].shooterCanMoveUp = false;
							if (shooterArray[counterS].enterShooterArrive == true)
							{
								shooterArray[counterS].timeShooterArrive = int(timerlevel2);
								shooterArray[counterS].enterShooterArrive = false;
								shooterArray[counterS].shooterAngry = true;
								Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
							}
							if ((int(timerlevel2) - shooterArray[counterS].timeShooterArrive) % 2 == 0 && shooterArray[counterS].shooterAngry == true)
							{
								shooterArray[counterS].enterShooterAttack = true;
								shooterArray[counterS].shooterAngry = false;
							}
							if (shooterArray[counterS].enterShooterAttack == true)
							{
								projectile2.shooterPlasma = true;
								projectile2.movementSpeed = 7;
								projectile2.direction = 1;
								projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
								plasmaArray.push_back(projectile2);
								soundplasma.play();
								projectile2.shooterPlasma = false;
								Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
								shooterArray[counterS].timeShooterATK = timerlevel2;
								shooterArray[counterS].shooterAngry = false;
								shooterArray[counterS].enterShooterAttack = false;

							}
							shooterArray[counterS].afterShooterArrive = timerlevel2;
							if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 2)
							{
								shooterArray[counterS].shooterAngry = true;
							}

						}
						else
						{
							shooterArray[counterS].shooterCanMoveUp = true;
							shooterArray[counterS].enterShooterArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().y > shooterArray[counterS].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = false;
						if (shooterArray[counterS].shooterCanMoveDown == true)
						{
							shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 0, 96, 96));
							if (Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 10)
							{
								shooterArray[counterS].rect.move(0, 1);
							}
							else
							{
								shooterArray[counterS].rect.move(0, enemy2.movementSpeed);
							}
						}
						if (Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 250 && abs(Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x) < 40 && abs(shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							shooterArray[counterS].shooterCanMoveDown = false;
							if (shooterArray[counterS].enterShooterArrive == true)
							{
								shooterArray[counterS].timeShooterArrive = int(timerlevel2);
								shooterArray[counterS].enterShooterArrive = false;
								shooterArray[counterS].shooterAngry = true;
								Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
							}
							if ((int(timerlevel2) - shooterArray[counterS].timeShooterArrive) % 2 == 0 && shooterArray[counterS].shooterAngry == true)
							{
								shooterArray[counterS].enterShooterAttack = true;
								shooterArray[counterS].shooterAngry = false;
							}
							if (shooterArray[counterS].enterShooterAttack == true)
							{
								projectile2.shooterPlasma = true;
								projectile2.movementSpeed = 7;
								projectile2.direction = 2;
								projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
								plasmaArray.push_back(projectile2);
								soundplasma.play();
								projectile2.shooterPlasma = false;
								Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
								shooterArray[counterS].timeShooterATK = timerlevel2;
								shooterArray[counterS].shooterAngry = false;
								shooterArray[counterS].enterShooterAttack = false;

							}
							shooterArray[counterS].afterShooterArrive = timerlevel2;
							if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 2)
							{
								shooterArray[counterS].shooterAngry = true;
							}
						}
						else
						{
							shooterArray[counterS].shooterCanMoveDown = true;
							shooterArray[counterS].enterShooterArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().x > shooterArray[counterS].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (shooterArray[counterS].shooterCanMoveRight == true)
						{
							shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 192, 96, 96));
							shooterArray[counterS].rect.move(enemy2.movementSpeed, 0);
							shooterArray[counterS].enterShooterArrive = true;
						}
						if (Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 250 && abs(Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 20) && abs(shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							shooterArray[counterS].shooterCanMoveRight = false;
							if (shooterArray[counterS].enterShooterArrive == true)
							{
								shooterArray[counterS].timeShooterArrive = int(timerlevel2);
								shooterArray[counterS].enterShooterArrive = false;
								shooterArray[counterS].shooterAngry = true;
								Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
							}
							if ((int(timerlevel2) - shooterArray[counterS].timeShooterArrive) % 1 == 0 && shooterArray[counterS].shooterAngry == true)
							{
								shooterArray[counterS].enterShooterAttack = true;
								shooterArray[counterS].shooterAngry = false;
							}
							if (shooterArray[counterS].enterShooterAttack == true)
							{
								projectile2.shooterPlasma = true;
								projectile2.movementSpeed = 7;
								projectile2.direction = 4;
								projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
								plasmaArray.push_back(projectile2);
								soundplasma.play();
								projectile2.shooterPlasma = false;
								Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
								shooterArray[counterS].timeShooterATK = timerlevel2;
								shooterArray[counterS].shooterAngry = false;
								shooterArray[counterS].enterShooterAttack = false;

							}
							shooterArray[counterS].afterShooterArrive = timerlevel2;
							if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 1)
							{
								shooterArray[counterS].shooterAngry = true;
							}
						}
						else
						{
							shooterArray[counterS].shooterCanMoveRight = true;
							shooterArray[counterS].enterShooterArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().x < shooterArray[counterS].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (shooterArray[counterS].shooterCanMoveLeft == true)
						{
							shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 288, 96, 96));
							shooterArray[counterS].rect.move(-enemy2.movementSpeed, 0);
						}
						if (shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 250 && abs(Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 20) && abs(shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							shooterArray[counterS].shooterCanMoveLeft = false;
							if (shooterArray[counterS].enterShooterArrive == true)
							{
								shooterArray[counterS].timeShooterArrive = int(timerlevel2);
								shooterArray[counterS].enterShooterArrive = false;
								shooterArray[counterS].shooterAngry = true;
								Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
							}
							if ((int(timerlevel2) - shooterArray[counterS].timeShooterArrive) % 1 == 0 && shooterArray[counterS].shooterAngry == true)
							{
								shooterArray[counterS].enterShooterAttack = true;
								shooterArray[counterS].shooterAngry = false;
							}
							if (shooterArray[counterS].enterShooterAttack == true)
							{
								projectile2.shooterPlasma = true;
								projectile2.movementSpeed = 7;
								projectile2.direction = 3;
								projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
								plasmaArray.push_back(projectile2);
								soundplasma.play();
								projectile2.shooterPlasma = false;
								Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
								shooterArray[counterS].timeShooterATK = timerlevel2;
								shooterArray[counterS].shooterAngry = false;
								shooterArray[counterS].enterShooterAttack = false;

							}
							shooterArray[counterS].afterShooterArrive = timerlevel2;
							if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 1)
							{
								shooterArray[counterS].shooterAngry = true;
							}

						}
						else
						{
							shooterArray[counterS].shooterCanMoveLeft = true;
							shooterArray[counterS].enterShooterArrive = true;
						}
					}
				}



				if (shooterArray[counterS].tempShooterRand == 1)
				{
					if (Player1.sprite.getPosition().x > shooterArray[counterS].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (shooterArray[counterS].shooterCanMoveRight == true)
						{
							shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 192, 96, 96));
							if (Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 10)
							{
								shooterArray[counterS].rect.move(1, 0);
							}
							else
							{
								shooterArray[counterS].rect.move(enemy2.movementSpeed, 0);
							}

							shooterArray[counterS].enterShooterArrive = true;
						}
						if (Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 250 && abs(Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 20) && abs(shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							shooterArray[counterS].shooterCanMoveRight = false;

							if (shooterArray[counterS].enterShooterArrive == true)
							{
								shooterArray[counterS].timeShooterArrive = int(timerlevel2);
								shooterArray[counterS].enterShooterArrive = false;
								shooterArray[counterS].shooterAngry = true;
								Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
							}
							if ((int(timerlevel2) - shooterArray[counterS].timeShooterArrive) % 1 == 0 && shooterArray[counterS].shooterAngry == true)
							{
								shooterArray[counterS].enterShooterAttack = true;
								shooterArray[counterS].shooterAngry = false;
							}
							if (shooterArray[counterS].enterShooterAttack == true)
							{
								projectile2.shooterPlasma = true;
								projectile2.movementSpeed = 7;
								projectile2.direction = 4;
								projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
								plasmaArray.push_back(projectile2);
								soundplasma.play();
								projectile2.shooterPlasma = false;
								Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
								shooterArray[counterS].timeShooterATK = timerlevel2;
								shooterArray[counterS].shooterAngry = false;
								shooterArray[counterS].enterShooterAttack = false;
							}
							shooterArray[counterS].afterShooterArrive = timerlevel2;
							if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 1)
							{
								shooterArray[counterS].shooterAngry = true;
							}
						}
						else
						{
							shooterArray[counterS].shooterCanMoveRight = true;
							shooterArray[counterS].enterShooterArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().x < shooterArray[counterS].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (shooterArray[counterS].shooterCanMoveLeft == true)
						{
							shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 288, 96, 96));
							if (Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 10)
							{
								shooterArray[counterS].rect.move(-1, 0);
							}
							else
							{
								shooterArray[counterS].rect.move(-enemy2.movementSpeed, 0);
							}
						}
						if (shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 250 && abs(Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 20) && abs(shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							shooterArray[counterS].shooterCanMoveLeft = false;
							if (shooterArray[counterS].enterShooterArrive == true)
							{
								shooterArray[counterS].timeShooterArrive = int(timerlevel2);
								shooterArray[counterS].enterShooterArrive = false;
								shooterArray[counterS].shooterAngry = true;
								Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
							}
							if ((int(timerlevel2) - shooterArray[counterS].timeShooterArrive) % 1 == 0 && shooterArray[counterS].shooterAngry == true)
							{
								shooterArray[counterS].enterShooterAttack = true;
								shooterArray[counterS].shooterAngry = false;
							}
							if (shooterArray[counterS].enterShooterAttack == true)
							{
								projectile2.shooterPlasma = true;
								projectile2.movementSpeed = 7;
								projectile2.direction = 3;
								projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
								plasmaArray.push_back(projectile2);
								soundplasma.play();
								projectile2.shooterPlasma = false;
								Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
								shooterArray[counterS].timeShooterATK = timerlevel2;
								shooterArray[counterS].shooterAngry = false;
								shooterArray[counterS].enterShooterAttack = false;
							}
							shooterArray[counterS].afterShooterArrive = timerlevel2;
							if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 1)
							{
								shooterArray[counterS].shooterAngry = true;
							}

						}
						else
						{
							shooterArray[counterS].shooterCanMoveLeft = true;
							shooterArray[counterS].enterShooterArrive = true;
						}
					}

					else if (Player1.sprite.getPosition().y < shooterArray[counterS].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = true;
						if (shooterArray[counterS].shooterCanMoveUp == true)
						{
							shooterArray[counterS].sprite.setTextureRect(sf::IntRect(0, 96, 96, 96));

							if (shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 10)
							{
								shooterArray[counterS].rect.move(0, -1);;
							}
							else
							{
								shooterArray[counterS].rect.move(0, -enemy2.movementSpeed);
							}
						}
						if (shooterArray[counterS].rect.getPosition().y - Player1.sprite.getPosition().y < 250 && abs(Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x < 40) && abs(shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							shooterArray[counterS].shooterCanMoveUp = false;
							if (shooterArray[counterS].enterShooterArrive == true)
							{
								shooterArray[counterS].timeShooterArrive = int(timerlevel2);
								shooterArray[counterS].enterShooterArrive = false;
								shooterArray[counterS].shooterAngry = true;
								Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
							}
							if ((int(timerlevel2) - shooterArray[counterS].timeShooterArrive) % 2 == 0 && shooterArray[counterS].shooterAngry == true)
							{
								shooterArray[counterS].enterShooterAttack = true;
								shooterArray[counterS].shooterAngry = false;
							}
							if (shooterArray[counterS].enterShooterAttack == true)
							{
								projectile2.shooterPlasma = true;
								projectile2.movementSpeed = 7;
								projectile2.direction = 1;
								projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
								plasmaArray.push_back(projectile2);
								soundplasma.play();
								projectile2.shooterPlasma = false;
								Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
								shooterArray[counterS].timeShooterATK = timerlevel2;
								shooterArray[counterS].shooterAngry = false;
								shooterArray[counterS].enterShooterAttack = false;

							}
							shooterArray[counterS].afterShooterArrive = timerlevel2;
							if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 2)
							{
								shooterArray[counterS].shooterAngry = true;
							}

						}
						else
						{
							shooterArray[counterS].shooterCanMoveUp = true;
							shooterArray[counterS].enterShooterArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().y > shooterArray[counterS].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = false;
						if (shooterArray[counterS].shooterCanMoveDown == true)
						{
							shooterArray[counterS].sprite.setTextureRect(sf::IntRect(counterWalkingShooter * 96, 0, 96, 96));
							if (Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 10)
							{
								shooterArray[counterS].rect.move(0, 1);
							}
							else
							{
								shooterArray[counterS].rect.move(0, enemy2.movementSpeed);
							}
						}
						if (Player1.sprite.getPosition().y - shooterArray[counterS].rect.getPosition().y < 250 && abs(Player1.sprite.getPosition().x - shooterArray[counterS].rect.getPosition().x) < 40 && abs(shooterArray[counterS].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							if (shooterArray[counterS].enterShooterArrive == true)
							{
								shooterArray[counterS].timeShooterArrive = int(timerlevel2);
								shooterArray[counterS].enterShooterArrive = false;
								shooterArray[counterS].shooterAngry = true;
								Player1.blood = Player1.blood + shooterArray[counterS].attackDamage;
							}
							if ((int(timerlevel2) - shooterArray[counterS].timeShooterArrive) % 2 == 0 && shooterArray[counterS].shooterAngry == true)
							{
								shooterArray[counterS].enterShooterAttack = true;
								shooterArray[counterS].shooterAngry = false;
							}
							if (shooterArray[counterS].enterShooterAttack == true)
							{
								projectile2.shooterPlasma = true;
								projectile2.movementSpeed = 7;
								projectile2.direction = 2;
								projectile2.sprite.setPosition(shooterArray[counterS].rect.getPosition().x - 25, shooterArray[counterS].rect.getPosition().y);
								plasmaArray.push_back(projectile2);
								soundplasma.play();
								projectile2.shooterPlasma = false;
								Player1.blood = Player1.blood - shooterArray[counterS].attackDamage;
								shooterArray[counterS].timeShooterATK = timerlevel2;
								shooterArray[counterS].shooterAngry = false;
								shooterArray[counterS].enterShooterAttack = false;
							}
							shooterArray[counterS].afterShooterArrive = timerlevel2;
							if (shooterArray[counterS].afterShooterArrive - shooterArray[counterS].timeShooterATK >= 2)
							{
								shooterArray[counterS].shooterAngry = true;
							}
						}
						else
						{
							shooterArray[counterS].shooterCanMoveDown = true;
							shooterArray[counterS].enterShooterArrive = true;
						}
					}
				}
				counterS++;
			}

			// Lavar Chase And Attack
			counterL = 0;
			for (iterLavar = lavarArray.begin(); iterLavar != lavarArray.end(); iterLavar++)
			{
				timerLavar = clock.getElapsedTime().asMilliseconds();
				if (timerLavar % 50 == 0)
				{
					lavarArray[counterL].tempLavarRand = rand() % 2;
				}
				if (lavarArray[counterL].tempLavarRand == 0)
				{
					if (Player1.sprite.getPosition().y < lavarArray[counterL].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = true;
						if (int(lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
						{
							lavarArray[counterL].counterWalkingLavar++;
						}
						if (lavarArray[counterL].lavarCanMoveUp == true)
						{
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterWalkingLavar * 96, 96, 96, 96));

							if (lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y < 10)
							{
								lavarArray[counterL].rect.move(0, -1);;
							}
							else
							{
								lavarArray[counterL].rect.move(0, -enemy3.movementSpeed);
							}
						}
						if (lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - lavarArray[counterL].rect.getPosition().x < 40) && abs(lavarArray[counterL].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							lavarArray[counterL].lavarCanMoveUp = false;
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterLavarAttack * 96, 672, 96, 96));
							lavarArray[counterL].counterLavarAttack++;
							if (lavarArray[counterL].enterLavarArrive == true)
							{
								lavarArray[counterL].timeLavarArrive = int(timerlevel2);
								lavarArray[counterL].enterLavarArrive = false;
								lavarArray[counterL].lavarAngry = true;
								Player1.blood = Player1.blood + lavarArray[counterL].attackDamage;
							}
							if ((int(timerlevel2) - lavarArray[counterL].timeLavarArrive) % 2 == 0 && lavarArray[counterL].lavarAngry == true)
							{
								lavarArray[counterL].enterLavarAttack = true;
								lavarArray[counterL].lavarAngry = false;
							}
							if (lavarArray[counterL].enterLavarAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - lavarArray[counterL].attackDamage;
								lavarArray[counterL].timeLavarATK = timerlevel2;
								lavarArray[counterL].lavarAngry = false;
								lavarArray[counterL].enterLavarAttack = false;

							}
							lavarArray[counterL].afterLavarArrive = timerlevel2;
							if (lavarArray[counterL].afterLavarArrive - lavarArray[counterL].timeLavarATK >= 2)
							{
								lavarArray[counterL].lavarAngry = true;
							}
						}
						else
						{
							lavarArray[counterL].lavarCanMoveUp = true;
							lavarArray[counterL].enterLavarArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().y > lavarArray[counterL].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = false;
						if (int(lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
						{
							lavarArray[counterL].counterWalkingLavar++;
						}
						if (lavarArray[counterL].lavarCanMoveDown == true)
						{
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterWalkingLavar * 96, 0, 96, 96));
							if (Player1.sprite.getPosition().y - lavarArray[counterL].rect.getPosition().y < 10)
							{
								lavarArray[counterL].rect.move(0, 1);
							}
							else
							{
								lavarArray[counterL].rect.move(0, enemy3.movementSpeed);
							}
						}
						if (Player1.sprite.getPosition().y - lavarArray[counterL].rect.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - lavarArray[counterL].rect.getPosition().x) < 40 && abs(lavarArray[counterL].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							lavarArray[counterL].lavarCanMoveDown = false;
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterLavarAttack * 96, 576, 96, 96));
							lavarArray[counterL].counterLavarAttack++;
							if (lavarArray[counterL].enterLavarArrive == true)
							{
								lavarArray[counterL].timeLavarArrive = int(timerlevel2);
								lavarArray[counterL].enterLavarArrive = false;
								lavarArray[counterL].lavarAngry = true;
								Player1.blood = Player1.blood + lavarArray[counterL].attackDamage;
							}
							if ((int(timerlevel2) - lavarArray[counterL].timeLavarArrive) % 2 == 0 && lavarArray[counterL].lavarAngry == true)
							{
								lavarArray[counterL].enterLavarAttack = true;
								lavarArray[counterL].lavarAngry = false;
							}
							if (lavarArray[counterL].enterLavarAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - lavarArray[counterL].attackDamage;
								lavarArray[counterL].timeLavarATK = timerlevel2;
								lavarArray[counterL].lavarAngry = false;
								lavarArray[counterL].enterLavarAttack = false;

							}
							lavarArray[counterL].afterLavarArrive = timerlevel2;
							if (lavarArray[counterL].afterLavarArrive - lavarArray[counterL].timeLavarATK >= 2)
							{
								lavarArray[counterL].lavarAngry = true;
							}

						}
						else
						{
							lavarArray[counterL].lavarCanMoveDown = true;
							lavarArray[counterL].enterLavarArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().x > lavarArray[counterL].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (int(lavarArray[counterL].rect.getPosition().x - Player1.sprite.getPosition().x) % 5 == 0)
						{
							lavarArray[counterL].counterWalkingLavar++;
						}
						if (lavarArray[counterL].lavarCanMoveRight == true)
						{
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterWalkingLavar * 96, 288, 96, 96));
							lavarArray[counterL].rect.move(enemy3.movementSpeed, 0);
							lavarArray[counterL].enterLavarArrive = true;
						}
						if (Player1.sprite.getPosition().x - lavarArray[counterL].rect.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - lavarArray[counterL].rect.getPosition().y < 20) && abs(lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							lavarArray[counterL].lavarCanMoveRight = false;
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterLavarAttack * 96, 480, 96, 96));
							lavarArray[counterL].counterLavarAttack++;
							if (lavarArray[counterL].enterLavarArrive == true)
							{
								lavarArray[counterL].timeLavarArrive = int(timerlevel2);
								lavarArray[counterL].enterLavarArrive = false;
								lavarArray[counterL].lavarAngry = true;
								Player1.blood = Player1.blood + lavarArray[counterL].attackDamage;
							}
							if ((int(timerlevel2) - lavarArray[counterL].timeLavarArrive) % 1 == 0 && lavarArray[counterL].lavarAngry == true)
							{
								lavarArray[counterL].enterLavarAttack = true;
								lavarArray[counterL].lavarAngry = false;
							}
							if (lavarArray[counterL].enterLavarAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - lavarArray[counterL].attackDamage;
								lavarArray[counterL].timeLavarATK = timerlevel2;
								lavarArray[counterL].lavarAngry = false;
								lavarArray[counterL].enterLavarAttack = false;

							}
							lavarArray[counterL].afterLavarArrive = timerlevel2;
							if (lavarArray[counterL].afterLavarArrive - lavarArray[counterL].timeLavarATK >= 1)
							{
								lavarArray[counterL].lavarAngry = true;
							}
						}
						else
						{
							lavarArray[counterL].lavarCanMoveRight = true;
							lavarArray[counterL].enterLavarArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().x < lavarArray[counterL].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (int(lavarArray[counterL].rect.getPosition().x - Player1.sprite.getPosition().x) % 5 == 0)
						{
							lavarArray[counterL].counterWalkingLavar++;
						}
						if (lavarArray[counterL].lavarCanMoveLeft == true)
						{
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterWalkingLavar * 96, 192, 96, 96));
							lavarArray[counterL].rect.move(-enemy3.movementSpeed, 0);
						}
						if (lavarArray[counterL].rect.getPosition().x - Player1.sprite.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - lavarArray[counterL].rect.getPosition().y < 20) && abs(lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							lavarArray[counterL].lavarCanMoveLeft = false;
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterLavarAttack * 96, 384, 96, 96));
							lavarArray[counterL].counterLavarAttack++;
							if (lavarArray[counterL].enterLavarArrive == true)
							{
								lavarArray[counterL].timeLavarArrive = int(timerlevel2);
								lavarArray[counterL].enterLavarArrive = false;
								lavarArray[counterL].lavarAngry = true;
								Player1.blood = Player1.blood + lavarArray[counterL].attackDamage;
							}
							if ((int(timerlevel2) - lavarArray[counterL].timeLavarArrive) % 1 == 0 && lavarArray[counterL].lavarAngry == true)
							{
								lavarArray[counterL].enterLavarAttack = true;
								lavarArray[counterL].lavarAngry = false;
							}
							if (lavarArray[counterL].enterLavarAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - lavarArray[counterL].attackDamage;
								lavarArray[counterL].timeLavarATK = timerlevel2;
								lavarArray[counterL].lavarAngry = false;
								lavarArray[counterL].enterLavarAttack = false;

							}
							lavarArray[counterL].afterLavarArrive = timerlevel2;
							if (lavarArray[counterL].afterLavarArrive - lavarArray[counterL].timeLavarATK >= 1)
							{
								lavarArray[counterL].lavarAngry = true;
							}

						}
						else
						{
							lavarArray[counterL].lavarCanMoveLeft = true;
							lavarArray[counterL].enterLavarArrive = true;
						}
					}
				}

				if (lavarArray[counterL].tempLavarRand == 1)
				{
					
					if (Player1.sprite.getPosition().x > lavarArray[counterL].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (int(lavarArray[counterL].rect.getPosition().x - Player1.sprite.getPosition().x) % 5 == 0)
						{
							lavarArray[counterL].counterWalkingLavar++;
						}
						if (lavarArray[counterL].lavarCanMoveRight == true)
						{
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterWalkingLavar * 96, 288, 96, 96));
							lavarArray[counterL].rect.move(enemy3.movementSpeed, 0);
							lavarArray[counterL].enterLavarArrive = true;
						}
						if (Player1.sprite.getPosition().x - lavarArray[counterL].rect.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - lavarArray[counterL].rect.getPosition().y < 20) && abs(lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							lavarArray[counterL].lavarCanMoveRight = false;
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterLavarAttack * 96, 480, 96, 96));
							lavarArray[counterL].counterLavarAttack++;
							if (lavarArray[counterL].enterLavarArrive == true)
							{
								lavarArray[counterL].timeLavarArrive = int(timerlevel2);
								lavarArray[counterL].enterLavarArrive = false;
								lavarArray[counterL].lavarAngry = true;
								Player1.blood = Player1.blood + lavarArray[counterL].attackDamage;
							}
							if ((int(timerlevel2) - lavarArray[counterL].timeLavarArrive) % 1 == 0 && lavarArray[counterL].lavarAngry == true)
							{
								lavarArray[counterL].enterLavarAttack = true;
								lavarArray[counterL].lavarAngry = false;
							}
							if (lavarArray[counterL].enterLavarAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - lavarArray[counterL].attackDamage;
								lavarArray[counterL].timeLavarATK = timerlevel2;
								lavarArray[counterL].lavarAngry = false;
								lavarArray[counterL].enterLavarAttack = false;

							}
							lavarArray[counterL].afterLavarArrive = timerlevel2;
							if (lavarArray[counterL].afterLavarArrive - lavarArray[counterL].timeLavarATK >= 1)
							{
								lavarArray[counterL].lavarAngry = true;
							}
						}
						else
						{
							lavarArray[counterL].lavarCanMoveRight = true;
							lavarArray[counterL].enterLavarArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().x < lavarArray[counterL].rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (int(lavarArray[counterL].rect.getPosition().x - Player1.sprite.getPosition().x) % 5 == 0)
						{
							lavarArray[counterL].counterWalkingLavar++;
						}
						if (lavarArray[counterL].lavarCanMoveLeft == true)
						{
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterWalkingLavar * 96, 192, 96, 96));
							lavarArray[counterL].rect.move(-enemy3.movementSpeed, 0);
						}
						if (lavarArray[counterL].rect.getPosition().x - Player1.sprite.getPosition().x < 60 && abs(Player1.sprite.getPosition().y - lavarArray[counterL].rect.getPosition().y < 20) && abs(lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							lavarArray[counterL].lavarCanMoveLeft = false;
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterLavarAttack * 96, 384, 96, 96));
							lavarArray[counterL].counterLavarAttack++;
							if (lavarArray[counterL].enterLavarArrive == true)
							{
								lavarArray[counterL].timeLavarArrive = int(timerlevel2);
								lavarArray[counterL].enterLavarArrive = false;
								lavarArray[counterL].lavarAngry = true;
								Player1.blood = Player1.blood + lavarArray[counterL].attackDamage;
							}
							if ((int(timerlevel2) - lavarArray[counterL].timeLavarArrive) % 1 == 0 && lavarArray[counterL].lavarAngry == true)
							{
								lavarArray[counterL].enterLavarAttack = true;
								lavarArray[counterL].lavarAngry = false;
							}
							if (lavarArray[counterL].enterLavarAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - lavarArray[counterL].attackDamage;
								lavarArray[counterL].timeLavarATK = timerlevel2;
								lavarArray[counterL].lavarAngry = false;
								lavarArray[counterL].enterLavarAttack = false;

							}
							lavarArray[counterL].afterLavarArrive = timerlevel2;
							if (lavarArray[counterL].afterLavarArrive - lavarArray[counterL].timeLavarATK >= 1)
							{
								lavarArray[counterL].lavarAngry = true;
							}

						}
						else
						{
							lavarArray[counterL].lavarCanMoveLeft = true;
							lavarArray[counterL].enterLavarArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().y < lavarArray[counterL].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = true;
						if (int(lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
						{
							lavarArray[counterL].counterWalkingLavar++;
						}
						if (lavarArray[counterL].lavarCanMoveUp == true)
						{
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterWalkingLavar * 96, 96, 96, 96));

							if (lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y < 10)
							{
								lavarArray[counterL].rect.move(0, -1);;
							}
							else
							{
								lavarArray[counterL].rect.move(0, -enemy3.movementSpeed);
							}
						}
						if (lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - lavarArray[counterL].rect.getPosition().x < 40) && abs(lavarArray[counterL].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							lavarArray[counterL].lavarCanMoveUp = false;
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterLavarAttack * 96, 672, 96, 96));
							lavarArray[counterL].counterLavarAttack++;
							if (lavarArray[counterL].enterLavarArrive == true)
							{
								lavarArray[counterL].timeLavarArrive = int(timerlevel2);
								lavarArray[counterL].enterLavarArrive = false;
								lavarArray[counterL].lavarAngry = true;
								Player1.blood = Player1.blood + lavarArray[counterL].attackDamage;
							}
							if ((int(timerlevel2) - lavarArray[counterL].timeLavarArrive) % 2 == 0 && lavarArray[counterL].lavarAngry == true)
							{
								lavarArray[counterL].enterLavarAttack = true;
								lavarArray[counterL].lavarAngry = false;
							}
							if (lavarArray[counterL].enterLavarAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - lavarArray[counterL].attackDamage;
								lavarArray[counterL].timeLavarATK = timerlevel2;
								lavarArray[counterL].lavarAngry = false;
								lavarArray[counterL].enterLavarAttack = false;

							}
							lavarArray[counterL].afterLavarArrive = timerlevel2;
							if (lavarArray[counterL].afterLavarArrive - lavarArray[counterL].timeLavarATK >= 2)
							{
								lavarArray[counterL].lavarAngry = true;
							}
						}
						else
						{
							lavarArray[counterL].lavarCanMoveUp = true;
							lavarArray[counterL].enterLavarArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().y > lavarArray[counterL].rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = false;
						if (int(lavarArray[counterL].rect.getPosition().y - Player1.sprite.getPosition().y) % 5 == 0)
						{
							lavarArray[counterL].counterWalkingLavar++;
						}
						if (lavarArray[counterL].lavarCanMoveDown == true)
						{
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterWalkingLavar * 96, 0, 96, 96));
							if (Player1.sprite.getPosition().y - lavarArray[counterL].rect.getPosition().y < 10)
							{
								lavarArray[counterL].rect.move(0, 1);
							}
							else
							{
								lavarArray[counterL].rect.move(0, enemy3.movementSpeed);
							}
						}
						if (Player1.sprite.getPosition().y - lavarArray[counterL].rect.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - lavarArray[counterL].rect.getPosition().x) < 40 && abs(lavarArray[counterL].rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							lavarArray[counterL].lavarCanMoveDown = false;
							lavarArray[counterL].sprite.setTextureRect(sf::IntRect(lavarArray[counterL].counterLavarAttack * 96, 576, 96, 96));
							lavarArray[counterL].counterLavarAttack++;
							if (lavarArray[counterL].enterLavarArrive == true)
							{
								lavarArray[counterL].timeLavarArrive = int(timerlevel2);
								lavarArray[counterL].enterLavarArrive = false;
								lavarArray[counterL].lavarAngry = true;
								Player1.blood = Player1.blood + lavarArray[counterL].attackDamage;
							}
							if ((int(timerlevel2) - lavarArray[counterL].timeLavarArrive) % 2 == 0 && lavarArray[counterL].lavarAngry == true)
							{
								lavarArray[counterL].enterLavarAttack = true;
								lavarArray[counterL].lavarAngry = false;
							}
							if (lavarArray[counterL].enterLavarAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - lavarArray[counterL].attackDamage;
								lavarArray[counterL].timeLavarATK = timerlevel2;
								lavarArray[counterL].lavarAngry = false;
								lavarArray[counterL].enterLavarAttack = false;

							}
							lavarArray[counterL].afterLavarArrive = timerlevel2;
							if (lavarArray[counterL].afterLavarArrive - lavarArray[counterL].timeLavarATK >= 2)
							{
								lavarArray[counterL].lavarAngry = true;
							}

						}
						else
						{
							lavarArray[counterL].lavarCanMoveDown = true;
							lavarArray[counterL].enterLavarArrive = true;
						}
					}
				}


				if (lavarArray[counterL].counterWalkingLavar >= 2)
				{
					lavarArray[counterL].counterWalkingLavar = 0;
				}

				if (lavarArray[counterL].counterLavarAttack >= 2)
				{
					lavarArray[counterL].counterLavarAttack = 0;
				}
				counterL++;
			}
			// Shooter's Plasma Collide with Player
			counter = 0;
			for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
			{
				if (plasmaArray[counter].shooterPlasma == true)
				{
					if (Collision::PixelPerfectTest(plasmaArray[counter].sprite, Player1.sprite))
					{
						soundhit.play();
						Player1.blood = Player1.blood - 3;
						plasmaArray[counter].destroy = true;
					}
				}
				counter++;
			}


			// Spawn Monster
			if (int(timerlevel2) == monsterSpawnTime && int(timerlevel2) != 0)
			{
				enemy1.rect.setPosition(rand() % 1800, rand() % 900);
				enemy1HP.sprite.setPosition(monsterArray[counter].sprite.getPosition().x, monsterArray[counter].sprite.getPosition().y - 20);
				HPmonsterArray.push_back(enemy1HP);
				monsterArray.push_back(enemy1);
				monsterSpawnTime = monsterSpawnTime + 2;
			}

			// Spawn Shooter
			if (int(timerlevel2) == shooterSpawnTime && int(timerlevel2) != 0)
			{
				enemy2.rect.setPosition(rand() % 1800, rand() % 900);
				enemy2HP.sprite.setPosition(shooterArray[counter].sprite.getPosition().x, shooterArray[counter].sprite.getPosition().y - 20);
				HPshooterArray.push_back(enemy2HP);
				shooterArray.push_back(enemy2);
				shooterSpawnTime = shooterSpawnTime + 10;
			}

			// Spawn Lavar
			if (int(timerlevel2) == lavarSpawnTime && int(timerlevel2) != 0)
			{
				enemy3.rect.setPosition(rand() % 1800, rand() % 900);
				enemy3HP.sprite.setPosition(lavarArray[counter].sprite.getPosition().x, lavarArray[counter].sprite.getPosition().y - 20);
				HPlavarArray.push_back(enemy3HP);
				lavarArray.push_back(enemy3);
				lavarSpawnTime = lavarSpawnTime + 15;
			}

			// Player Attack Monster
			counter2 = 0;
			for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
			{
				if (Collision::PixelPerfectTest(Player1.sprite, monsterArray[counter2].sprite) && keyspace == 1)
				{
					enterAttack = true;
					if (enterAttack == true)
					{
						monsterArray[counter2].blood = monsterArray[counter2].blood - Player1.attackDamage;
						HPmonsterArray[counter2].sprite.setTextureRect(sf::IntRect(0, 0, (96 * monsterArray[counter2].blood) / 15, 96));
						if (monsterArray[counter2].blood <= 0)
						{
							monsterArray[counter2].alive = false;
							HPmonsterArray[counter2].alive = false;
							soundkill.play();
							score += 1200;
							_itoa_s(score, bufferScore, 10);
						}
						enterAttack = false;
					}
					keyspace = 0;
				}
				counter2++;
			}

			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				counter2 = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					if (Collision::PixelPerfectTest(projectileArray[counter].sprite, monsterArray[counter2].sprite))
					{
						soundbomb.play();
						projectileArray[counter].destroy = true;
						monsterArray[counter2].blood = monsterArray[counter2].blood - projectileArray[counter].attackDamage;
						HPmonsterArray[counter2].sprite.setTextureRect(sf::IntRect(0, 0, (96 * monsterArray[counter2].blood) / 15, 96));
						if (monsterArray[counter2].blood <= 0)
						{
							monsterArray[counter2].alive = false;
							HPmonsterArray[counter2].alive = false;
							soundkill.play();
							score += 200;
							_itoa_s(score, bufferScore, 10);
						}
					}
					counter2++;
				}
				counter++;
			}

			// Player Attack Shooter
			counter2 = 0;
			for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
			{
				if (Collision::PixelPerfectTest(Player1.sprite, shooterArray[counter2].sprite) && keyspace == 1)
				{
					enterAttack = true;
					if (enterAttack == true)
					{
						shooterArray[counter2].blood = shooterArray[counter2].blood - Player1.attackDamage;
						HPshooterArray[counter2].sprite.setTextureRect(sf::IntRect(0, 0, (96 * shooterArray[counter2].blood) / 10, 96));
						if (shooterArray[counter2].blood <= 0)
						{
							shooterArray[counter2].alive = false;
							HPshooterArray[counter2].alive = false;
							soundbomb.play();
							score += 1700;
							_itoa_s(score, bufferScore, 10);
						}
						enterAttack = false;
					}
					keyspace = 0;
				}
				counter2++;
			}

			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				counter2 = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					if (Collision::PixelPerfectTest(projectileArray[counter].sprite, shooterArray[counter2].sprite))
					{
						soundbomb.play();
						projectileArray[counter].destroy = true;
						shooterArray[counter2].blood = shooterArray[counter2].blood - projectileArray[counter].attackDamage;
						HPshooterArray[counter2].sprite.setTextureRect(sf::IntRect(0, 0, (96 * shooterArray[counter2].blood) / 10, 96));
						if (shooterArray[counter2].blood <= 0)
						{
							shooterArray[counter2].alive = false;
							HPshooterArray[counter2].alive = false;
							soundbomb.play();
							score += 700;
							_itoa_s(score, bufferScore, 10);
						}
					}
					counter2++;
				}
				counter++;
			}

			//Player Attack Lavar
			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				counter4 = 0;
				for (iterLavar = lavarArray.begin(); iterLavar != lavarArray.end(); iterLavar++)
				{
					if (Collision::PixelPerfectTest(projectileArray[counter].sprite, lavarArray[counter4].sprite))
					{
						soundbomb.play();
						projectileArray[counter].destroy = true;
						lavarArray[counter4].blood = lavarArray[counter4].blood - projectileArray[counter].attackDamage;
						HPlavarArray[counter4].sprite.setTextureRect(sf::IntRect(0, 0, (96 * lavarArray[counter4].blood) / 20, 96));
						if (lavarArray[counter4].blood <= 0)
						{
							lavarArray[counter4].alive = false;
							HPlavarArray[counter4].alive = false;
							soundkill.play();
							score += 2000;
							_itoa_s(score, bufferScore, 10);
						}
					}
					counter4++;
				}
				counter++;
			}

			


			// Draw Bullet
			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				if (projectileArray[counter].sprite.getPosition().x < 0 || projectileArray[counter].sprite.getPosition().x > 1850 || projectileArray[counter].sprite.getPosition().y < 0 || projectileArray[counter].sprite.getPosition().y > 1000)
				{
					projectileArray[counter].destroy = true;
				}
				projectileArray[counter].update();
				window.draw(projectileArray[counter].sprite);
				counter++;
			}

			// Draw Plasma
			counter = 0;
			for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
			{
				if (plasmaArray[counter].sprite.getPosition().x < 0 || plasmaArray[counter].sprite.getPosition().x > 1850 || plasmaArray[counter].sprite.getPosition().y < 0 || plasmaArray[counter].sprite.getPosition().y > 1000)
				{
					plasmaArray[counter].destroy = true;
				}
				plasmaArray[counter].update();
				window.draw(plasmaArray[counter].sprite);
				counter++;
			}

			// Fire Bullet
			if (keyC == 1 && powerBullet == true)
			{
				soundshoot.play();
				projectileArray.push_back(projectile1);
				keyC = 0;
			}

			// Check Direction Bullet
			projectile1.direction = Player1.checkDirection;
			if (projectile1.direction == 1)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 128, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}

				projectile1.sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x - 60, Player1.sprite.getPosition().y - 80);

			}
			if (projectile1.direction == 2)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}

				projectile1.sprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x - 5, Player1.sprite.getPosition().y - 40);
			}
			if (projectile1.direction == 3)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 384, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}

				projectile1.sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x - 95, Player1.sprite.getPosition().y - 60);
			}
			if (projectile1.direction == 4)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 256, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}

				projectile1.sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x + 15, Player1.sprite.getPosition().y - 60);
			}
		
			// Bronze Coin
			if (int(timerlevel2) % 1 == 0 && enterBronzeCoin == 0 && int(timerlevel2) != 0)
			{
				enterBronzeCoin = 1;
				spriteBronzeCoin.setTextureRect(sf::IntRect(0, 0, 96, 96));
				bronzeCoinpx = rand() % 1800;
				bronzeCoinpy = rand() % 900;

			}
			if (enterBronzeCoin == 1)
			{
				spriteBronzeCoin.setPosition(bronzeCoinpx, bronzeCoinpy);
				window.draw(spriteBronzeCoin);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteBronzeCoin))
			{
				soundcoin.play();
				spriteBronzeCoin.setTextureRect(sf::IntRect(0, 0, 0, 0));
				score = score + 10;
				_itoa_s(score, bufferScore, 10);
				enterBronzeCoin = 0;
			}

			
			// Silver Coin
			if (int(timerlevel2) % 3 == 0 && enterSilverCoin == 0 && int(timerlevel2) != 0)
			{
				enterSilverCoin = 1;
				spriteSilverCoin.setTextureRect(sf::IntRect(0, 0, 96, 96));
				silverCoinpx = rand() % 1800;
				silverCoinpy = rand() % 900;

			}
			if (enterSilverCoin == 1)
			{
				spriteSilverCoin.setPosition(silverCoinpx, silverCoinpy);
				window.draw(spriteSilverCoin);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteSilverCoin))
			{
				soundcoin.play();
				spriteSilverCoin.setTextureRect(sf::IntRect(0, 0, 0, 0));
				score = score + 50;
				_itoa_s(score, bufferScore, 10);
				enterSilverCoin = 0;
			}

			// Gold Coin
			if (int(timerlevel2) % 5 == 0 && enterCoin == 0 && int(timerlevel2) != 0)
			{
				enterCoin = 1;
				spriteGoldCoin.setTextureRect(sf::IntRect(0, 0, 80, 80));
				goldCoinpx = rand() % 1800;
				goldCoinpy = rand() % 900;

			}
			if (enterCoin == 1)
			{
				spriteGoldCoin.setPosition(goldCoinpx, goldCoinpy);
				window.draw(spriteGoldCoin);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteGoldCoin))
			{
				soundcoin.play();
				spriteGoldCoin.setTextureRect(sf::IntRect(0, 0, 0, 0));
				score = score + 100;
				_itoa_s(score, bufferScore, 10);
				enterCoin = 0;
			}

			// Aid
			if (int(timerlevel2) % 10 == 0 && enterAid == 0 && int(timerlevel2) != 0)
			{
				enterAid = 1;
				spriteAid.setTextureRect(sf::IntRect(0, 0, 80, 80));
				aidpx = rand() % 1800;
				aidpy = rand() % 900;

			}
			if (enterAid == 1)
			{
				spriteAid.setPosition(aidpx, aidpy);
				window.draw(spriteAid);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteAid))
			{
				soundaidcoin.play();
				spriteAid.setTextureRect(sf::IntRect(0, 0, 0, 0));
				Player1.blood = Player1.blood + 20;
				if (Player1.blood > 100)
				{
					Player1.blood = 100;
				}
				enterAid = 0;
			}

			// Gun
			if (int(timerlevel2) % 15 == 0 && enterGun == 0 && int(timerlevel2) != 0)
			{
				enterGun = 1;
				spriteGun.setTextureRect(sf::IntRect(0, 0, 80, 80));
				gunpx = rand() % 1800;
				gunpy = rand() % 900;

			}
			if (enterGun == 1)
			{
				spriteGun.setPosition(gunpx, gunpy);
				window.draw(spriteGun);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteGun))
			{
				soundguncoin.play();
				spriteGun.setTextureRect(sf::IntRect(0, 0, 0, 0));
				powerBullet = true;
				getBullet = int(timerlevel2);
				enterGun = 0;
			}

			if (int(timerlevel2) - getBullet > 5)
			{
				powerBullet = false;
			}


			// text score
			window.draw(textscore);
			textscore.setPosition(Player1.sprite.getPosition().x - 600, Player1.sprite.getPosition().y - 320);
			textscore.setString("score : ");

			// text point
			window.draw(textpoint);
			textpoint.setPosition(Player1.sprite.getPosition().x - 450, Player1.sprite.getPosition().y - 320);
			textpoint.setString(bufferScore);
			if (score == 0)
			{
				_itoa_s(score, bufferScore, 10);
			}

			// text time
			window.draw(textTimeLevel2);
			textTimeLevel2.setPosition(Player1.sprite.getPosition().x, Player1.sprite.getPosition().y - 320);
			textTimeLevel2.setString(bufferTimeLevel2);

			// text health
			window.draw(textHealth);
			textHealth.setPosition(Player1.sprite.getPosition().x + 130, Player1.sprite.getPosition().y - 320);
			textHealth.setString(bufferHealth);
			_itoa_s(Player1.blood, bufferHealth, 10);


			// draw HP bar
			window.draw(spriteHPb);
			window.draw(spriteHPr);
			spriteHPr.setTextureRect(sf::IntRect(0, 0, Player1.blood, 40));
			spriteHPr.setPosition(Player1.sprite.getPosition().x + 195, Player1.sprite.getPosition().y - 320);

			spriteHPb.setTextureRect(sf::IntRect(0, 0, 100, 10));
			spriteHPb.setPosition(Player1.sprite.getPosition().x + 195, Player1.sprite.getPosition().y - 320);


			// Lose 
			if (Player1.blood <= 0)
			{
				counterM = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					monsterArray[counterM].alive = false;
					HPmonsterArray[counterM].alive = false;
					counterM++;
				}

				counterS = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					shooterArray[counterS].alive = false;
					HPshooterArray[counterS].alive = false;
					counterS++;
				}

				counterL = 0;
				for (iterLavar = lavarArray.begin(); iterLavar != lavarArray.end(); iterLavar++)
				{
					lavarArray[counterL].alive = false;
					HPlavarArray[counterL].alive = false;
					counterL++;
				}

				counterP = 0;
				for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
				{
					plasmaArray[counterP].destroy = true;
				}
				soundGameOver = true;
				formLevel2 = true;
				level = 999;
			}

			// Win
			if (int(timerlevel2) == 150)
			{
				counterM = 0;
				for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
				{
					monsterArray[counterM].alive = false;
					HPmonsterArray[counterM].alive = false;
					counterM++;
				}

				counterS = 0;
				for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
				{
					shooterArray[counterS].alive = false;
					HPshooterArray[counterS].alive = false;
					counterS++;
				}

				counterL = 0;
				for (iterLavar = lavarArray.begin(); iterLavar != lavarArray.end(); iterLavar++)
				{
					lavarArray[counterL].alive = false;
					HPlavarArray[counterL].alive = false;
					counterL++;
				}

				counterP = 0;
				for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
				{
					plasmaArray[counterP].destroy = true;
					counterP++;
				}

				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					projectileArray[counter].destroy = true;
					counter++;
				}

				enemy4.movementSpeed = 4;
				enemy4.attackDamage = 5;
				enemy4.blood = 200;
				Player1.attackDamage = 2;
				projectile1.attackDamage = 4;
				loadingScene3 = true;
				restartTimeLoadingScene3 = true;
				formLevel2 = false;
			}

			if (goExit == true)
			{
				musicMenu.stop();
				musicStage1.stop();
				musicStage2.stop();
				musicStage3.stop();
				Player1.blood = 100;
				Player1.attackDamage = 5;
				monsterSpawnTime = 5;
				shooterSpawnTime = 10;
				lavarSpawnTime = 20;
				enemy1.movementSpeed = 1;
				enemy2.movementSpeed = 1;
				enemy3.movementSpeed = 1;
				restarttimelevel0 = 1;
				restarttimelevel1 = 1;
				restarttimelevel2 = 1;
				restarttimelevel3 = 1;
				timerlevel1 = 0;
				timerlevel2 = 0;
				timerlevel3 = 0;
				restartTimeLoadingScene = true;
				restartTimeLoadingScene2 = true;
				restartTimeLoadingScene3 = true;
				powerBullet = false;
				pause = false;
				play = false;
				score = 0;

				sf::View view2(sf::FloatRect(200, 200, 300, 200));
				view2.setSize(sf::Vector2f(1920, 1080));
				view2.setCenter(sf::Vector2f(view2.getSize().x / 2, view2.getSize().y / 2));
				window.setView(view2);
				level = 0;
				goExit = false;
			}

			// Deleted Death Monsters
			counter = 0;
			for (iterMonster = monsterArray.begin(); iterMonster != monsterArray.end(); iterMonster++)
			{
				if (monsterArray[counter].alive == false)
				{
					monsterArray.erase(iterMonster);
					break;
				}
				counter++;
			}

			counter = 0;
			for (iterHPMonster = HPmonsterArray.begin(); iterHPMonster != HPmonsterArray.end(); iterHPMonster++)
			{
				if (HPmonsterArray[counter].alive == false)
				{
					HPmonsterArray.erase(iterHPMonster);
					break;
				}
				counter++;
			}

			// Deleted Death Shooter
			counter = 0;
			for (iterShooter = shooterArray.begin(); iterShooter != shooterArray.end(); iterShooter++)
			{
				if (shooterArray[counter].alive == false)
				{
					shooterArray.erase(iterShooter);
					break;
				}
				counter++;
			}

			counter = 0;
			for (iterHPshooter = HPshooterArray.begin(); iterHPshooter != HPshooterArray.end(); iterHPshooter++)
			{
				if (HPshooterArray[counter].alive == false)
				{
					HPshooterArray.erase(iterHPshooter);
					break;
				}
				counter++;
			}

			// Deleted Death Lavar
			counter = 0;
			for (iterLavar = lavarArray.begin(); iterLavar != lavarArray.end(); iterLavar++)
			{
				if (lavarArray[counter].alive == false)
				{
					lavarArray.erase(iterLavar);
					break;
				}
				counter++;
			}

			counter = 0;
			for (iterHPLavar = HPlavarArray.begin(); iterHPLavar != HPlavarArray.end(); iterHPLavar++)
			{
				if (HPlavarArray[counter].alive == false)
				{
					HPlavarArray.erase(iterHPLavar);
					break;
				}
				counter++;
			}

			// Delete Bullet
			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				if (projectileArray[counter].destroy == true)
				{
					projectileArray.erase(iter);
					break;
				}
				counter++;
			}

			// Delete Plasma
			counter = 0;
			for (iterPlasma = plasmaArray.begin(); iterPlasma != plasmaArray.end(); iterPlasma++)
			{
				if (plasmaArray[counter].destroy == true)
				{
					plasmaArray.erase(iterPlasma);
					break;
				}
				counter++;
			}
		}

		// Loading Scene Level 3 Boss
		if (loadingScene3 == true)
		{
			if (restartTimeLoadingScene3 == true)
			{
				clock.restart();
				restartTimeLoadingScene3 = false;
			}
			timerLoadingScene3 = clock.getElapsedTime().asSeconds();
			if (timerLoadingScene3 < 5.00)
			{

				sf::View view2(sf::FloatRect(200, 200, 300, 200));
				view2.setSize(sf::Vector2f(1920, 1080));
				view2.setCenter(sf::Vector2f(view2.getSize().x / 2, view2.getSize().y / 2));
				window.setView(view2);
				window.draw(spriteLoadingSceneLevel3);
				Player1.sprite.setPosition(960, 540);
				Player1.attackDamage = 2;
				Player1.blood = 100;
			}
			else
			{
				level = 3;
			}
		}
		
		// Level 3 Boss Battle
		if (level == 3)
		{
			loadingScene3 = false;
			if (restarttimelevel3 == 1)
			{
				clock.restart();
				musicStage1.stop();
				musicStage2.stop();
				musicStage3.play();
				restarttimelevel3 = 0;
			}

		
			// timer 
			timerlevel3milli = clock.getElapsedTime().asMilliseconds();
			if (pause == false)
			{
				gtime3 = ctime3;
				ctime3 = clock.getElapsedTime().asSeconds();
				if (gtime3 != ctime3)
				{
					enterTimeLevel3 = true;
				}

				if (ctime3 % 1 == 0 && enterTimeLevel3 == true)
				{
					if (pause == false)
					{
						timerlevel3++;
						if (ctime3 % 2 == 0 && enterTimeLevel3 == true)
						{
							enemy4.blood += 2;
							if (enemy4.blood >= 200)
							{
								enemy4.blood = 200;
							}
						}
					}
					enterTimeLevel3 = false;
				}

			}
			// Pause
			if (pause == true)
			{
				if (play == true)
				{
					pause = false;
					play = false;
				}
			}

			if (int(timerlevel3) % 1 == 0 && enterTime3 == 1)
			{
				nowtimelevel3 = timerlevel3;
				_itoa_s(int(timerlevel3), bufferTimeLevel3, 10);
				enterTime3 = 0;
			}
			aftercounttimelevel3 = timerlevel3;
			if (aftercounttimelevel3 - nowtimelevel3 >= 1)
			{
				enterTime3 = 1;
			}

			//view
			window.setView(view1);


			// player sword attack
			if (keyspace == 1)
			{
				deltatimeplayerattacksword = timerlevel3milli - playerattackswordtime;
				if (deltatimeplayerattacksword < 150)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 640, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 512, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 768, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 896, 128, 128));
					}
				}
				if (deltatimeplayerattacksword >= 150 && deltatimeplayerattacksword < 300)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 640, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 512, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 768, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(128, 896, 128, 128));
					}
				}
				if (deltatimeplayerattacksword >= 300 && deltatimeplayerattacksword < 450)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 640, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 512, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 768, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(256, 896, 128, 128));
					}
				}
				if (deltatimeplayerattacksword > 450)
				{
					if (Player1.checkDirection == 1)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 128, 128, 128));
					}
					if (Player1.checkDirection == 2)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
					}
					if (Player1.checkDirection == 3)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 256, 128, 128));
					}
					if (Player1.checkDirection == 4)
					{
						Player1.sprite.setTextureRect(sf::IntRect(0, 384, 128, 128));
					}
					keyspace = 0;
				}
			}


			window.clear();
			window.draw(spriteLevel3BehideBackground);
			window.draw(spriteLevel3Background);

			if (drawPlayerBeforeEnemy == true)
			{
				// Draw Player
				window.draw(Player1.sprite);
				window.draw(spriteShoulderCannon);

				//  Draw Boss
				enemy4.update();

				window.draw(enemy4.sprite);
				
			}

			if (drawPlayerBeforeEnemy == false)
			{
				//  Draw Boss
				enemy4.update();
	
				window.draw(enemy4.sprite);
				
				// Draw Player
				window.draw(Player1.sprite);
				window.draw(spriteShoulderCannon);
			}

		

			// Update Player
			Player1.update();
			Player1.updateMovement();


			// Player View
			window.setView(view1);
			view1.setCenter(Player1.sprite.getPosition());

			// Destroy All
			
			if (goExit == true || loadingScene3 == true)
			{
				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					projectileArray[counter].destroy = true;
					counter++;
				}

				musicStage3.stop();
				level = 0;
				sf::View view2(sf::FloatRect(200, 200, 300, 200));
				view2.setSize(sf::Vector2f(1920, 1080));
				view2.setCenter(sf::Vector2f(view2.getSize().x / 2, view2.getSize().y / 2));
				window.setView(view2);

				// Reset Valuable to Normal
				Player1.blood = 100;
				Player1.attackDamage = 5;
				monsterSpawnTime = 5;
				shooterSpawnTime = 5;
				lavarSpawnTime = 5;
				enemy1.blood = 10;
				enemy1.movementSpeed = 1;
				enemy2.movementSpeed = 1;
				enemy3.movementSpeed = 1;
				restarttimelevel0 = 1;
				restarttimelevel1 = 1;
				restarttimelevel2 = 1;
				restarttimelevel3 = 1;
				timerlevel1 = 0;
				timerlevel2 = 0;
				timerlevel3 = 0;
				restartTimeLoadingScene = true;
				restartTimeLoadingScene2 = true;
				restartTimeLoadingScene3 = true;
				powerBullet = false;
				pause = false;
				play = false;
				goExit = false;
			}

			// Boss Chase And Attack

			timerBoss = clock.getElapsedTime().asMilliseconds();
			if (timerBoss % 50 == 0)
			{

			}

			if (enemy4.tempBossRand == 0)
			{
				if (Player1.sprite.getPosition().y - enemy4.rect.getPosition().y < 30)
				{
					drawPlayerBeforeEnemy = true;
					if (int(enemy4.rect.getPosition().y - Player1.sprite.getPosition().y) % 10 == 0)
					{
						enemy4.counterWalkingBoss++;
					}
					if (enemy4.bossCanMoveUp == true)
					{
						if (enemy4.blood > 0)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterWalkingBoss * 160, 160, 160, 160));
						}

						if (enemy4.rect.getPosition().y - Player1.sprite.getPosition().y < 15)
						{
							enemy4.rect.move(0, -1);;
						}
						else
						{
							enemy4.rect.move(0, -enemy4.movementSpeed);
						}
					}
					if (enemy4.rect.getPosition().y - Player1.sprite.getPosition().y < 10 && abs(Player1.sprite.getPosition().x - enemy4.rect.getPosition().x < 40) && abs(enemy4.rect.getPosition().x - Player1.sprite.getPosition().x < 40))
					{
						enemy4.bossCanMoveUp = false;
						if (enemy4.blood > 0)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterBossAttack * 160, 1120, 160, 160));
						}
						enemy4.counterBossAttack++;
						if (enemy4.enterBossArrive == true)
						{
							enemy4.timeBossArrive = int(timerlevel3);
							enemy4.enterBossArrive = false;
							enemy4.bossAngry = true;
						}
						if ((int(timerlevel3) - enemy4.timeBossArrive) % 2 == 0 && enemy4.bossAngry == true)
						{
							enemy4.enterBossAttack = true;
							enemy4.bossAngry = false;
						}
						if (enemy4.enterBossAttack == true)
						{
							if (enemy4.blood > 0)
							{
								Player1.blood = Player1.blood - enemy4.attackDamage;
							}
							enemy4.timeBossATK = timerlevel3;
							enemy4.bossAngry = false;
							enemy4.enterBossAttack = false;

						}
						enemy4.afterBossArrive = timerlevel3;
						if (enemy4.afterBossArrive - enemy4.timeBossATK >= 2)
						{
							enemy4.bossAngry = true;
						}

					}
					else
					{
						enemy4.bossCanMoveUp = true;
						enemy4.enterBossArrive = true;
					}
				}
				else if (Player1.sprite.getPosition().y > enemy4.rect.getPosition().y && Player1.sprite.getPosition().y - enemy4.rect.getPosition().y >50)
				{
					drawPlayerBeforeEnemy = false;
					if (int(enemy4.rect.getPosition().y - Player1.sprite.getPosition().y) % 10 == 0)
					{
						enemy4.counterWalkingBoss++;
					}
					if (enemy4.bossCanMoveDown == true)
					{
						if (enemy4.blood > 0)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterWalkingBoss * 160, 0, 160, 160));
						}
						if (Player1.sprite.getPosition().y - enemy4.rect.getPosition().y < 10)
						{
							enemy4.rect.move(0, 1);
						}
						else
						{
							enemy4.rect.move(0, enemy4.movementSpeed);
						}
					}
					if (Player1.sprite.getPosition().y - enemy4.rect.getPosition().y < 100 && abs(Player1.sprite.getPosition().x - enemy4.rect.getPosition().x) < 120 && abs(enemy4.rect.getPosition().x - Player1.sprite.getPosition().x < 120))
					{
						enemy4.bossCanMoveDown = false;
						if (enemy4.blood > 0)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterBossAttack * 160, 960, 160, 160));
						}
						enemy4.counterBossAttack++;
						if (enemy4.enterBossArrive == true)
						{
							enemy4.timeBossArrive = int(timerlevel3);
							enemy4.enterBossArrive = false;
							enemy4.bossAngry = true;
						}
						if ((int(timerlevel3) - enemy4.timeBossArrive) % 2 == 0 && enemy4.bossAngry == true)
						{
							enemy4.enterBossAttack = true;
							enemy4.bossAngry = false;
						}
						if (enemy4.enterBossAttack == true)
						{
							if (enemy4.blood > 0)
							{
								Player1.blood = Player1.blood - enemy4.attackDamage;
							}
							enemy4.timeBossATK = timerlevel3;
							enemy4.bossAngry = false;
							enemy4.enterBossAttack = false;

						}
						enemy4.afterBossArrive = timerlevel3;
						if (enemy4.afterBossArrive - enemy4.timeBossATK >= 2)
						{
							enemy4.bossAngry = true;
						}

					}
					else
					{
						enemy4.bossCanMoveDown = true;
						enemy4.enterBossArrive = true;
					}
				}
			    else if (Player1.sprite.getPosition().x > enemy4.rect.getPosition().x)
				{
					drawPlayerBeforeEnemy = false;
					if (int(enemy4.rect.getPosition().x - Player1.sprite.getPosition().x) % 10 == 0)
					{
						enemy4.counterWalkingBoss++;
					}
					if (enemy4.bossCanMoveRight == true)
					{
						if (enemy4.blood > 0)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterWalkingBoss * 160, 480, 160, 160));
						}
						enemy4.rect.move(enemy4.movementSpeed, 0);
						enemy4.enterBossArrive = true;
					}
					if (Player1.sprite.getPosition().x - enemy4.rect.getPosition().x < 120 && abs(Player1.sprite.getPosition().y - enemy4.rect.getPosition().y < 100) && abs(enemy4.rect.getPosition().y - Player1.sprite.getPosition().y < 100))
					{
						enemy4.bossCanMoveRight = false;
						if (enemy4.blood > 0)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterBossAttack * 160, 800, 160, 160));
						}
						enemy4.counterBossAttack++;
						if (enemy4.enterBossArrive == true)
						{
							enemy4.timeBossArrive = int(timerlevel3);
							enemy4.enterBossArrive = false;
							enemy4.bossAngry = true;
						}
						if ((int(timerlevel2) - enemy4.timeBossArrive) % 1 == 0 && enemy4.bossAngry == true)
						{
							enemy4.enterBossAttack = true;
							enemy4.bossAngry = false;
						}
						if (enemy4.enterBossAttack == true)
						{
							if (enemy4.blood > 0)
							{
								Player1.blood = Player1.blood - enemy4.attackDamage;
							}
							enemy4.timeBossATK = timerlevel3;
							enemy4.bossAngry = false;
							enemy4.enterBossAttack = false;

						}
						enemy4.afterBossArrive = timerlevel3;
						if (enemy4.afterBossArrive - enemy4.timeBossATK >= 1)
						{
							enemy4.bossAngry = true;
						}
					}
					else
					{
						enemy4.bossCanMoveRight = true;
						enemy4.enterBossArrive = true;
					}
				}
				else if (Player1.sprite.getPosition().x < enemy4.rect.getPosition().x)
				{
					drawPlayerBeforeEnemy = false;
					if (int(enemy4.rect.getPosition().x - Player1.sprite.getPosition().x) % 10 == 0)
					{
						enemy4.counterWalkingBoss++;
					}
					if (enemy4.bossCanMoveLeft == true)
					{
						if (enemy4.blood > 0)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterWalkingBoss * 160, 320, 160, 160));
						}
						enemy4.rect.move(-enemy4.movementSpeed, 0);
					}
					if (enemy4.rect.getPosition().x - Player1.sprite.getPosition().x < 50 && abs(Player1.sprite.getPosition().y - enemy4.rect.getPosition().y < 1000) && abs(enemy4.rect.getPosition().y - Player1.sprite.getPosition().y < 1000))
					{
						enemy4.bossCanMoveLeft = false;
						if (enemy4.blood > 0)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterBossAttack * 160, 640, 160, 160));
							enemy4.counterBossAttack++;
						}
						if (enemy4.enterBossArrive == true)
						{
							enemy4.timeBossArrive = int(timerlevel3);
							enemy4.enterBossArrive = false;
							enemy4.bossAngry = true;
						}
						if ((int(timerlevel3) - enemy4.timeBossArrive) % 1 == 0 && enemy4.bossAngry == true)
						{
							enemy4.enterBossAttack = true;
							enemy4.bossAngry = false;
						}
						if (enemy4.enterBossAttack == true)
						{
							if (enemy4.blood > 0)
							{
								Player1.blood = Player1.blood - enemy4.attackDamage;
							}
							enemy4.timeBossATK = timerlevel3;
							enemy4.bossAngry = false;
							enemy4.enterBossAttack = false;

						}
						enemy4.afterBossArrive = timerlevel3;
						if (enemy4.afterBossArrive - enemy4.timeBossATK >= 1)
						{
							enemy4.bossAngry = true;
						}

					}
					else
					{
						enemy4.bossCanMoveLeft = true;
						enemy4.enterBossArrive = true;
					}
				}
			}
				if (enemy4.tempBossRand == 1)
				{
					if (Player1.sprite.getPosition().x > enemy4.rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (int(enemy4.rect.getPosition().x - Player1.sprite.getPosition().x) % 10 == 0)
						{
							enemy4.counterWalkingBoss++;
						}
						if (enemy4.bossCanMoveRight == true)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterWalkingBoss * 160, 480, 160, 160));
							enemy4.rect.move(enemy4.movementSpeed, 0);
							enemy4.enterBossArrive = true;
						}
						if (Player1.sprite.getPosition().x - enemy4.rect.getPosition().x < 100 && abs(Player1.sprite.getPosition().y - enemy4.rect.getPosition().y < 150) && abs(enemy4.rect.getPosition().y - Player1.sprite.getPosition().y < 150))
						{
							enemy4.bossCanMoveRight = false;
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterBossAttack * 160, 800, 160, 160));
							enemy4.counterBossAttack++;
							if (enemy4.enterBossArrive == true)
							{
								enemy4.timeBossArrive = int(timerlevel3);
								enemy4.enterBossArrive = false;
								enemy4.bossAngry = true;
							}
							if ((int(timerlevel2) - enemy4.timeBossArrive) % 1 == 0 && enemy4.bossAngry == true)
							{
								enemy4.enterBossAttack = true;
								enemy4.bossAngry = false;
							}
							if (enemy4.enterBossAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - enemy4.attackDamage;
								enemy4.timeBossATK = timerlevel3;
								enemy4.bossAngry = false;
								enemy4.enterBossAttack = false;

							}
							enemy4.afterBossArrive = timerlevel3;
							if (enemy4.afterBossArrive - enemy4.timeBossATK >= 1)
							{
								enemy4.bossAngry = true;
							}
						}
						else
						{
							enemy4.bossCanMoveRight = true;
							enemy4.enterBossArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().x < enemy4.rect.getPosition().x)
					{
						drawPlayerBeforeEnemy = false;
						if (int(enemy4.rect.getPosition().x - Player1.sprite.getPosition().x) % 10 == 0)
						{
							enemy4.counterWalkingBoss++;
						}
						if (enemy4.bossCanMoveLeft == true)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterWalkingBoss * 160, 320, 160, 160));
							enemy4.rect.move(-enemy4.movementSpeed, 0);
						}
						if (enemy4.rect.getPosition().x - Player1.sprite.getPosition().x < 120 && abs(Player1.sprite.getPosition().y - enemy4.rect.getPosition().y < 20) && abs(enemy4.rect.getPosition().y - Player1.sprite.getPosition().y < 20))
						{
							enemy4.bossCanMoveLeft = false;
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterBossAttack * 160, 640, 160, 160));
							enemy4.counterBossAttack++;
							if (enemy4.enterBossArrive == true)
							{
								enemy4.timeBossArrive = int(timerlevel3);
								enemy4.enterBossArrive = false;
								enemy4.bossAngry = true;
							}
							if ((int(timerlevel3) - enemy4.timeBossArrive) % 1 == 0 && enemy4.bossAngry == true)
							{
								enemy4.enterBossAttack = true;
								enemy4.bossAngry = false;
							}
							if (enemy4.enterBossAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - enemy4.attackDamage;
								enemy4.timeBossATK = timerlevel3;
								enemy4.bossAngry = false;
								enemy4.enterBossAttack = false;

							}
							enemy4.afterBossArrive = timerlevel3;
							if (enemy4.afterBossArrive - enemy4.timeBossATK >= 1)
							{
								enemy4.bossAngry = true;
							}

						}
						else
						{
							enemy4.bossCanMoveLeft = true;
							enemy4.enterBossArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().y < enemy4.rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = true;
						if (int(enemy4.rect.getPosition().y - Player1.sprite.getPosition().y) % 10 == 0)
						{
							enemy4.counterWalkingBoss++;
						}
						if (enemy4.bossCanMoveUp == true)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterWalkingBoss * 160, 160, 160, 160));

							if (enemy4.rect.getPosition().y - Player1.sprite.getPosition().y < 15)
							{
								enemy4.rect.move(0, -1);;
							}
							else
							{
								enemy4.rect.move(0, -enemy4.movementSpeed);
							}
						}
						if (enemy4.rect.getPosition().y - Player1.sprite.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - enemy4.rect.getPosition().x < 40) && abs(enemy4.rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							enemy4.bossCanMoveUp = false;
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterBossAttack * 160, 1120, 160, 160));
							enemy4.counterBossAttack++;
							if (enemy4.enterBossArrive == true)
							{
								enemy4.timeBossArrive = int(timerlevel3);
								enemy4.enterBossArrive = false;
								enemy4.bossAngry = true;
								//Player1.blood = Player1.blood + enemy4.attackDamage;
							}
							if ((int(timerlevel3) - enemy4.timeBossArrive) % 2 == 0 && enemy4.bossAngry == true)
							{
								enemy4.enterBossAttack = true;
								enemy4.bossAngry = false;
							}
							if (enemy4.enterBossAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - enemy4.attackDamage;
								enemy4.timeBossATK = timerlevel3;
								enemy4.bossAngry = false;
								enemy4.enterBossAttack = false;

							}
							enemy4.afterBossArrive = timerlevel3;
							if (enemy4.afterBossArrive - enemy4.timeBossATK >= 2)
							{
								enemy4.bossAngry = true;
							}

						}
						else
						{
							enemy4.bossCanMoveUp = true;
							enemy4.enterBossArrive = true;
						}
					}
					else if (Player1.sprite.getPosition().y > enemy4.rect.getPosition().y)
					{
						drawPlayerBeforeEnemy = false;
						if (int(enemy4.rect.getPosition().y - Player1.sprite.getPosition().y) % 10 == 0)
						{
							enemy4.counterWalkingBoss++;
						}
						if (enemy4.bossCanMoveDown == true)
						{
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterWalkingBoss * 160, 0, 160, 160));
							if (Player1.sprite.getPosition().y - enemy4.rect.getPosition().y < 10)
							{
								enemy4.rect.move(0, 1);
							}
							else
							{
								enemy4.rect.move(0, enemy4.movementSpeed);
							}
						}
						if (Player1.sprite.getPosition().y - enemy4.rect.getPosition().y < 60 && abs(Player1.sprite.getPosition().x - enemy4.rect.getPosition().x) < 40 && abs(enemy4.rect.getPosition().x - Player1.sprite.getPosition().x < 40))
						{
							enemy4.bossCanMoveDown = false;
							enemy4.sprite.setTextureRect(sf::IntRect(enemy4.counterBossAttack * 160, 960, 160, 160));
							enemy4.counterBossAttack++;
							if (enemy4.enterBossArrive == true)
							{
								enemy4.timeBossArrive = int(timerlevel3);
								enemy4.enterBossArrive = false;
								enemy4.bossAngry = true;
								//Player1.blood = Player1.blood + enemy4.attackDamage;
							}
							if ((int(timerlevel3) - enemy4.timeBossArrive) % 2 == 0 && enemy4.bossAngry == true)
							{
								enemy4.enterBossAttack = true;
								enemy4.bossAngry = false;
							}
							if (enemy4.enterBossAttack == true)
							{
								soundhit.play();
								Player1.blood = Player1.blood - enemy4.attackDamage;
								enemy4.timeBossATK = timerlevel3;
								enemy4.bossAngry = false;
								enemy4.enterBossAttack = false;

							}
							enemy4.afterBossArrive = timerlevel3;
							if (enemy4.afterBossArrive - enemy4.timeBossATK >= 2)
							{
								enemy4.bossAngry = true;
							}

						}
						else
						{
							enemy4.bossCanMoveDown = true;
							enemy4.enterBossArrive = true;
						}
					}
                }
				if (enemy4.counterWalkingBoss >= 2)
				{
					enemy4.counterWalkingBoss = 0;
				}

				if (enemy4.counterBossAttack >= 2)
				{
					enemy4.counterBossAttack = 0;
				}
			
				// Player Attack Boss
				
				if (Collision::PixelPerfectTest(Player1.sprite,enemy4.sprite) && keyspace == 1)
				{
					enterAttack = true;
						if (enterAttack == true)
						{
							enemy4.blood = enemy4.blood - Player1.attackDamage;
							if (enemy4.blood == 0)
							{
								soundkill.play();
								score += 10000;
								_itoa_s(score, bufferScore, 10);
								enemy4.sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
							}
							enterAttack = false;
						}
						keyspace = 0;
				}

				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					if (Collision::PixelPerfectTest(projectileArray[counter].sprite, enemy4.sprite))
					{
						soundbomb.play();
						projectileArray[counter].destroy = true;
						enemy4.blood = enemy4.blood - projectile1.attackDamage;
						if (enemy4.blood == 0)
						{
							soundkill.play();
							score += 10000;
							_itoa_s(score, bufferScore, 10);
							enemy4.sprite.setTextureRect(sf::IntRect(0,0,0,0));
						}	
					}
					counter++;
				}


			// Draw Bullet
			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				if (projectileArray[counter].sprite.getPosition().x < 0 || projectileArray[counter].sprite.getPosition().x > 1850 || projectileArray[counter].sprite.getPosition().y < 0 || projectileArray[counter].sprite.getPosition().y > 1000)
				{
					projectileArray[counter].destroy = true;
				}
				projectileArray[counter].update();
				window.draw(projectileArray[counter].sprite);
				counter++;
			}


			// Fire Bullet
			if (keyC == 1 && powerBullet == true)
			{
				soundshoot.play();
				projectileArray.push_back(projectile1);
				keyC = 0;
			}

			// Check Direction Bullet
			projectile1.direction = Player1.checkDirection;
			if (projectile1.direction == 1)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 128, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}

				projectile1.sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x - 60, Player1.sprite.getPosition().y - 80);

			}
			if (projectile1.direction == 2)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}

				projectile1.sprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x - 5, Player1.sprite.getPosition().y - 40);
			}
			if (projectile1.direction == 3)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 384, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}

				projectile1.sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x - 95, Player1.sprite.getPosition().y - 60);
			}
			if (projectile1.direction == 4)
			{
				if (powerBullet == true)
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 256, 128, 128));
					spriteShoulderCannon.setPosition(Player1.sprite.getPosition().x - 65, Player1.sprite.getPosition().y - 58);
				}
				else
				{
					spriteShoulderCannon.setTextureRect(sf::IntRect(0, 0, 0, 0));
				}

				projectile1.sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
				projectile1.sprite.setPosition(Player1.sprite.getPosition().x + 15, Player1.sprite.getPosition().y - 60);
			}


			// Bronze Coin
			if (int(timerlevel3) % 1 == 0 && enterBronzeCoin == 0 && int(timerlevel3) != 0)
			{
				enterBronzeCoin = 1;
				spriteBronzeCoin.setTextureRect(sf::IntRect(0, 0, 96, 96));
				bronzeCoinpx = rand() % 1800;
				bronzeCoinpy = rand() % 900;

			}
			if (enterBronzeCoin == 1)
			{
				spriteBronzeCoin.setPosition(bronzeCoinpx, bronzeCoinpy);
				window.draw(spriteBronzeCoin);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteBronzeCoin))
			{
				soundcoin.play();
				spriteBronzeCoin.setTextureRect(sf::IntRect(0, 0, 0, 0));
				score = score + 10;
				_itoa_s(score, bufferScore, 10);
				enterBronzeCoin = 0;
			}


			// Silver Coin
			if (int(timerlevel3) % 3 == 0 && enterSilverCoin == 0 && int(timerlevel3) != 0)
			{
				enterSilverCoin = 1;
				spriteSilverCoin.setTextureRect(sf::IntRect(0, 0, 96, 96));
				silverCoinpx = rand() % 1800;
				silverCoinpy = rand() % 900;

			}
			if (enterSilverCoin == 1)
			{
				spriteSilverCoin.setPosition(silverCoinpx, silverCoinpy);
				window.draw(spriteSilverCoin);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteSilverCoin))
			{
				soundcoin.play();
				spriteSilverCoin.setTextureRect(sf::IntRect(0, 0, 0, 0));
				score = score + 100;
				_itoa_s(score, bufferScore, 10);
				enterSilverCoin = 0;
			}

			// Gold Coin
			if (int(timerlevel3) % 5 == 0 && enterCoin == 0 && int(timerlevel3) != 0)
			{
				enterCoin = 1;
				spriteGoldCoin.setTextureRect(sf::IntRect(0, 0, 80, 80));
				goldCoinpx = rand() % 1800;
				goldCoinpy = rand() % 900;

			}
			if (enterCoin == 1)
			{
				spriteGoldCoin.setPosition(goldCoinpx, goldCoinpy);
				window.draw(spriteGoldCoin);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteGoldCoin))
			{
				soundcoin.play();
				spriteGoldCoin.setTextureRect(sf::IntRect(0, 0, 0, 0));
				score = score + 100;
				_itoa_s(score, bufferScore, 10);
				enterCoin = 0;
			}

			// Aid
			if (int(timerlevel3) % 15 == 0 && enterAid == 0 && int(timerlevel3) != 0)
			{
				enterAid = 1;
				spriteAid.setTextureRect(sf::IntRect(0, 0, 80, 80));
				aidpx = rand() % 1800;
				aidpy = rand() % 900;

			}
			if (enterAid == 1)
			{
				spriteAid.setPosition(aidpx, aidpy);
				window.draw(spriteAid);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteAid))
			{
				soundaidcoin.play();
				spriteAid.setTextureRect(sf::IntRect(0, 0, 0, 0));
				Player1.blood = Player1.blood + 20;
				if (Player1.blood > 100)
				{
					Player1.blood = 100;
				}
				enterAid = 0;
			}

			// Gun
			if (int(timerlevel3) % 10 == 0 && enterGun == 0 && int(timerlevel3) != 0)
			{
				enterGun = 1;
				spriteGun.setTextureRect(sf::IntRect(0, 0, 80, 80));
				gunpx = rand() % 1800;
				gunpy = rand() % 900;

			}
			if (enterGun == 1)
			{
				spriteGun.setPosition(gunpx, gunpy);
				window.draw(spriteGun);
			}
			if (Collision::PixelPerfectTest(Player1.sprite, spriteGun))
			{
				soundguncoin.play();
				spriteGun.setTextureRect(sf::IntRect(0, 0, 0, 0));
				powerBullet = true;
				getBullet = int(timerlevel3);
				enterGun = 0;
			}

			if (int(timerlevel3) - getBullet > 2)
			{
				powerBullet = false;
			}


			// text score
			window.draw(textscore);
			textscore.setPosition(Player1.sprite.getPosition().x - 600, Player1.sprite.getPosition().y - 320);
			textscore.setString("score : ");

			// text point
			window.draw(textpoint);
			textpoint.setPosition(Player1.sprite.getPosition().x - 450, Player1.sprite.getPosition().y - 320);
			textpoint.setString(bufferScore);
			if (score == 0)
			{
				_itoa_s(score, bufferScore, 10);
			}

			// text time
			window.draw(textTimeLevel3);
			textTimeLevel3.setPosition(Player1.sprite.getPosition().x, Player1.sprite.getPosition().y - 320);
			textTimeLevel3.setString(bufferTimeLevel3);

			// text health
			window.draw(textHealth);
			textHealth.setPosition(Player1.sprite.getPosition().x + 130, Player1.sprite.getPosition().y - 320);
			textHealth.setString(bufferHealth);
			_itoa_s(Player1.blood, bufferHealth, 10);

			// draw HP bar
			window.draw(spriteHPb);
			window.draw(spriteHPr);
			spriteHPr.setTextureRect(sf::IntRect(0, 0, Player1.blood, 40));
			spriteHPr.setPosition(Player1.sprite.getPosition().x + 195, Player1.sprite.getPosition().y - 320);

			spriteHPb.setTextureRect(sf::IntRect(0, 0, 100, 10));
			spriteHPb.setPosition(Player1.sprite.getPosition().x + 195, Player1.sprite.getPosition().y - 320);

			window.draw(enemy4HPr.sprite);
			window.draw(enemy4HPb.sprite);
			window.draw(textBoss);
			textBoss.setPosition(Player1.sprite.getPosition().x - 580, Player1.sprite.getPosition().y + 285);
			enemy4HPr.sprite.setTextureRect(sf::IntRect(0, 0,enemy4.blood/2 , 40));
			enemy4HPr.sprite.setPosition(Player1.sprite.getPosition().x-25, Player1.sprite.getPosition().y+500);
			enemy4HPb.sprite.setTextureRect(sf::IntRect(0, 0, 100, 10));
			enemy4HPb.sprite.setPosition(Player1.sprite.getPosition().x-25, Player1.sprite.getPosition().y+500);
			enemy4HPr.sprite.setScale(12, 4);
			enemy4HPb.sprite.setScale(12, 4);


			// Lose 
			if (Player1.blood < 0)
			{
				formLevel3 = true;
				level = 999;
				soundGameOver = true;
			}

			// Win
			if (enemy4.blood <= 0)
			{
				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					projectileArray[counter].destroy = true;
					counter++;
				}
				enemy4.sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
				level = 555;
				soundGameVictory = true;
				endgame = true;
			}

			// Delete Bullet
			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				if (projectileArray[counter].destroy == true)
				{
					projectileArray.erase(iter);
					break;
				}
				counter++;
			}
		}

	




        // Level Lose
		if (level == 999)
		{
			// set music
			musicMenu.stop();
			musicStage1.stop();
			musicStage2.stop();
			musicStage3.stop();
			if (soundGameOver == true)
			{
				musicGameOver.play();
				soundGameOver = false;
			}

			// set view
			sf::View view2(sf::FloatRect(200, 200, 300, 200));
			view2.setSize(sf::Vector2f(1920, 1080));
			view2.setCenter(sf::Vector2f(view2.getSize().x / 2, view2.getSize().y / 2));
			window.setView(view2);
			window.draw(spriteLose);

			// set valuable to normal
			Player1.blood = 100;
			Player1.attackDamage = 5;
			monsterSpawnTime = 5;
			shooterSpawnTime = 5;
			lavarSpawnTime = 5;
			enemy1.blood = 10;
			enemy1.movementSpeed = 1;
			enemy2.movementSpeed = 1;
			enemy3.movementSpeed = 1;
			restarttimelevel0 = 1;
			restarttimelevel1 = 1;
			restarttimelevel2 = 1;
			restarttimelevel3 = 1;
			timerlevel1 = 0;
			timerlevel2 = 0;
			timerlevel3 = 0;
			restartTimeLoadingScene = true;
			restartTimeLoadingScene2 = true;
			restartTimeLoadingScene3 = true;
			powerBullet = false;
			score = 0;
		}


		if (level == 555)
		{
			if (endgame == true)
			{
				// Set Music
				musicMenu.stop();
				musicStage1.stop();
				musicStage2.stop();
				musicStage3.stop();
				if (soundGameVictory == true)
				{
					musicVictory.play();
					soundGameVictory = false;
				}

				// Set View
				sf::View view2(sf::FloatRect(200, 200, 300, 200));
				view2.setSize(sf::Vector2f(1920, 1080));
				view2.setCenter(sf::Vector2f(view2.getSize().x / 2, view2.getSize().y / 2));
				window.setView(view2);

				// Draw Background
				window.draw(spriteWin);

				

				// Draw Name Box
				sf::RectangleShape playerName;
				playerName.setSize(sf::Vector2f(500, 70));
				playerName.setPosition(1920 / 2, 1080 / 2);
				playerName.setOrigin(250, 35);
				window.draw(playerName);
				

				totalTime += clock.restart().asSeconds();
				if (totalTime >= 0.5)
				{
					totalTime = 0;
					state = !state;
				}
				if (state == true)
				{
					window.draw(cursor);
				}

				if (event.type == sf::Event::EventType::TextEntered)
				{
					if (last_char != event.text.unicode && event.text.unicode == 8 && input.length() > 0)
					{
						last_char = event.text.unicode;
						input.erase(input.length() - 1);
						textName.setString(input);
						cursor.setPosition(((1920 / 2) - 220) + textName.getGlobalBounds().width - 5, 1080 / 2);
					}
					else if (last_char != event.text.unicode &&
						(event.text.unicode >= 'a' && event.text.unicode <= 'z' ||
						 event.text.unicode >= 'A' && event.text.unicode <= 'Z' ||
					     event.text.unicode >= '0' && event.text.unicode <= '9' ))
					{
						last_char = event.text.unicode;
						input += event.text.unicode;
						textName.setString(input);
						cursor.setPosition(((1920 / 2)-220) + textName.getGlobalBounds().width + 5, 1080 / 2);
					}
				}

				if (event.type == sf::Event::EventType::KeyReleased && last_char != ' ')
				{
					last_char = ' ';
				}

				window.draw(textName);
				_itoa_s(score, scoree, 10);
				textPoint.setString(scoree);
				window.draw(textPoint);

				// Reset Valuable to Normal
				Player1.blood = 100;
				Player1.attackDamage = 5;
				monsterSpawnTime = 5;
				shooterSpawnTime = 5;
				lavarSpawnTime = 5;
				enemy1.blood = 10;
				enemy1.movementSpeed = 1;
				enemy2.movementSpeed = 1;
				enemy3.movementSpeed = 1;
				restarttimelevel0 = 1;
				restarttimelevel1 = 1;
				restarttimelevel2 = 1;
				restarttimelevel3 = 1;
				timerlevel1 = 0;
				timerlevel2 = 0;
				timerlevel3 = 0;
				restartTimeLoadingScene = true;
				restartTimeLoadingScene2 = true;
				restartTimeLoadingScene3 = true;
				powerBullet = false;

				// Save Score and Name
				if (saveScore == true) 
				{
					
					std::fstream myfile;
					myfile.open("name.txt", std::ios::in | std::ios::out | std::ios::app);
					myfile << input;
					myfile << "\n";
					myfile.close();


					std::fstream myfile2;
					_itoa_s(score, scoree, 10);
					myfile2.open("score.txt", std::ios::in | std::ios::out | std::ios::app);
					myfile2 << scoree;
					myfile2 << "\n";
					myfile2.close();


					level = 0;
					sf::View view2(sf::FloatRect(200, 200, 300, 200));
					view2.setSize(sf::Vector2f(1920, 1080));
					view2.setCenter(sf::Vector2f(view2.getSize().x / 2, view2.getSize().y / 2));
					window.setView(view2);
					input = ' ';
					score = 0;
					saveScore = false;
				}
			}
		}

		if (level == 444)
		{
			sf::View view2(sf::FloatRect(200, 200, 300, 200));
			view2.setSize(sf::Vector2f(1920, 1080));
			view2.setCenter(sf::Vector2f(view2.getSize().x / 2, view2.getSize().y / 2));
			window.setView(view2);

			window.draw(spritePause);
			if (goExit == true && formLevel1 == true)
			{
				level = 1;
				formLevel1 = false;
			}
			if (goExit == true && formLevel2 == true)
			{
				level = 2;
				formLevel2 = false;
			}
			if (goExit == true && formLevel3 == true)
			{
				level = 3;
				formLevel3 = false;
			}
		}
		window.display();
	}
	return 0;
}
inherit NPC;

void create()
{
	set_name("船長",({"ship leader","leader"}));
	set("long","一個六七十歲的老頭 , 正小心翼翼的開著船 !\n");
	set("gender","男性");
	set("combat_exp",3000);
        set("attitude","heroism");
	set("age",65);
	set("str",30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("unarmed",40);
	set_skill("dodge",30);
	set_skill("parry",30);
	set("chat_chance",20);
	set("chat_msg",({
	"海浪拍打著船身 , 濺起一陣陣的海花 !\n",
	"突然來了一陣大浪 , 船好像快翻了似的 !\n",
	"往外看去是一片汪洋大海 , 真是美麗啊 !\n",
	}));
	setup();
	add_money("silver",10);
}
 int accept_kill(object me)
 {
	return notify_fail("船長怒道 : 砍我 , 找死啊 , 你會游泳啊 ?\n");
  }
 int accept_fight(object me)
 {
	 return notify_fail("船長喝道 :幹什麼 , 船已經快翻啦 , 還敢在這裡打打殺殺 ?\n");
 }

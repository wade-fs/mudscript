inherit NPC;

void create()
{
	set_name("船孃",({"ship girl","girl"}));
	set("long","一個雙十年華的姑娘 , 以優美的姿態操控著船 !\n");
	set("gender","女性");
	set("combat_exp",30000);
        set("attitude","heroism");
	set("age",20);
	set("str",30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("unarmed",40);
	set_skill("dodge",60);
	set_skill("parry",60);
	set("chat_chance",20);
	set("chat_msg",({
	"海浪拍打著船身 , 濺起一陣陣的海花 !\n",
	"耳邊傳來陣陣的海浪聲及海鳥的叫聲令人悠然入夢 !\n",
	"放眼望去是一片的碧海藍天 , 真是美麗啊 !\n",
	}));
	setup();
	add_money("silver",10);
}
 int accept_kill(object me)
 {
	return notify_fail("船孃說道 : 既然如此我就不客氣了!\n");
  }
 int accept_fight(object me)
 {
	 return notify_fail("船孃害怕道 : 不要欺負弱小好嗎:~~~~\n");
 }

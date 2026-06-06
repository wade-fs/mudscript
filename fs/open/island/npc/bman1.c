
inherit NPC;

void create()
{
        set_name("老船夫",({"boat man","man"}));
        set("long","一位年近古稀的老人 , 但眼底閃著精光 !\n");
        set("gender","男性");
        set("combat_exp",300000);
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
        set_skill("unarmed",300);
        set_skill("dodge",200);
       set_skill("parry",260);
        set("chat_chance",20);
        set("chat_msg",({
        "海浪拍打著船身 , 濺起一陣陣的海花 !\n",
        "耳邊傳來陣陣的海浪聲及海鳥的叫聲令人悠然入夢 !\n",
        "放眼望去是一片的碧海藍天 , 真是美麗啊 !\n",
        }));
        setup();
        add_money("coin",100);
}
 int accept_kill(object me)
 {
        return notify_fail("船夫說道 : 既然如此我就不客氣了!\n");
  }
 int accept_fight(object me)
 {
         return notify_fail("船夫歎道 : 真是沒禮數的年輕人\n");
 }




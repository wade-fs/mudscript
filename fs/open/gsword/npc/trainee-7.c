#include "/open/gsword/npc/attack_bloodsword.h"

inherit NPC;

void create()
{
	set_name("柳若芙",({"ro fu","fu"}));
set("long","柳毅之女,年方十七,千驕百媚.為李逍遙之愛徒.\n");
	set("gender","女性");
	set("combat_exp",3613);
        set("attitude","heroism");
	set("age",17);
	set("class","swordsman");
	set("force",150);
	set("max_force",150);
	set("family/master_name","李逍遙");
	set("chat_chance",10);
       set_skill("shasword",10);
       set_skill("sha-steps",3);
       map_skill("sword","shasword");
       map_skill("dodge","sha-steps");
	set("chat_msg",({
  "柳若芙滿面愁容道:都是我不好,使大師兄被師父責罰在私過崖面壁一個月，
  其實我只是想跟師兄玩個捉迷藏，看到前面有條小路，我就衝進去了，哪知 
  道師父會大發雷霆。\n",
  "柳若芙嘟著嘴道 : 跟你們說哦...那天聽到我爹和掌門--鄭士欣叔叔談論什麼『仙劍
   後三式』的 ,好像神秘兮兮..還提到『藏經閣』之類 ,真不知道他們在做什麼..\n", 
  "柳若芙嘟著嘴道:那裡面除了一些怪聲音，和一堆動物的殘骸之外，也不見有
  什麼奇怪之處，不過小路盡頭有個山洞感覺怪怪的，不過裡面這麼黑，我也不
  敢進去。\n"
	 }));
	set("force_factor",3);
	set("str",30);
        set("cor", 30);
	set("per",35);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("sword",35);
	set_skill("dodge",35);
	set_skill("parry",35);
	setup();
	carry_object("/obj/longsword.c")->wield();
	carry_object("/open/gsword/obj/robe_1")->wear();
	add_money("silver",5);
	create_family("仙劍派",5,"弟子");
	setup();
}

         
      

inherit NPC;

void create()
{
	set_name("魯連",({"ru lian","ru","lian"}));
	set("long",@LONG
只知他是仙劍的成員之一 ,在仙劍派已有很長的一段時間由於他偶而會說些
仙劍的古事給大家聽 ,所以門徒們都對他頗尊敬.
LONG);
	set("gender","男性");
	set("combat_exp",10000);
        set("attitude","heroism");
	set("age",23);
	set("title","仙劍派長者");
	set("class","swordsman");
	set("force",500);
	set("max_force",500);
	set("force_factor",5);
	set("str",30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("chat_chance",6);
	set("chat_msg",({
        "老者道: 仙劍派創派已有一百餘年 ,祖師爺--逍遙子--在創派後約五年\n
 的某場戰役中 ,不幸受了嚴重的內傷 ,將掌門之位傳給第二代掌門人後\n ,
 就此隱退江湖 ,雲遊四海。\n",
        "魯連道: 祖師爺臨走前特別吩咐我們不可接近禁地 ,原因他也沒跟我們說\n
 清楚 ,我想大概只有掌門人知道吧。\n",
          }));	
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("sword",60);
	set("inquiry",([
        "古事": "我正在說咩 ,安靜聽啦...。\n",
        "禁地": "你們千萬別去那裡哦 ,後果不堪設想的 ,說不定仙劍派會就此毀在
        你手上。\n",
	]));
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("move",40);
	set_skill("literate",40);
	set_skill("force",40);
	setup();
	carry_object("/obj/longsword.c")->wield();
	carry_object("/open/gsword/obj/robe_1")->wear();
	create_family("仙劍派",3,"弟子");
}

         
      

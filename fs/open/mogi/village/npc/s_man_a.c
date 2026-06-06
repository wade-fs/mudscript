

inherit NPC;
void create()
{
        set_name("村民",({"man"}));
        set("title","魔界村居民");
	set("gender", "男性" );
        set("age",31);
        set("str",35);
        set("cor",45);
	set("cps",25);
	set("int",15);
	set("long","魔界村的普通居民, 正忙著自己的事!\n");
	set("combat_exp",350);
	set("attitude", "peaceful");
        set("chat_chance", 25);
        set("chat_msg", ({
            "村民: 聽說天邪峰上有一隻千年冰蟾, 頭上的豎目是體內的丹元所化.\n",
            "村民: 魔界中有種仙界的植物叫(三葉仙蘭).\n",
            "村民: 傳說好幾年前有位仙劍的高手被困在妖魔古堡中.\n",
              (: this_object(),"random_move" :),
        }) );
	set_skill("parry", 15);
        set_skill("dodge", 5);
	setup();
         	
}


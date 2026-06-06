
inherit NPC;

void create()
{
        set_name("狂亂月",({"general mudu"}));
        set("title","襄陽城大將軍");
        set("long","
狂亂月本為鄭士欣得意弟子之一，武功\大成後反出師門，
墮入血魔一脈，然而天資有限，血魔霸劍式終究無法領悟完全 
，最後落的魔性入腦，神識大損
，終日瘋瘋癲癲。
在重新悔改後現在是一位為國盡心盡力的大將軍！正在此招募軍
人來抵擋蒙古大軍的入侵。
");
        set("str",30);
        set("con",31);
        set("cor",31);
        set("int",31);
        set("per",10);
        set("max_kee",50000);
        set("max_gin",50000);
        set("max_sen",50000);
        set("age",64);
        set("family/family_name","仙劍派");
        set("combat_exp",3000000);
        set("attitude","heroism");
        set("dragon-sword",1);
        set("functions/sha_kee/level",100);
        set("functions/swordkee/level",100);
        set("get_sha_sp", 1);
        set("quests/sunfire",1);
        set("quest/sun_fire_sword",1);
        set("bounds", 4000000);
        set_temp("roared",1);
        set("chat_msg", 5);
        set("chat_msg", ({
              "狂亂月說道: 守城人手不足，不知道有沒人可以加入(join)幫忙抵抗入侵。\n",
              "狂亂月說道: 蒙古真是越來越強大了。\n"

              }) );

        set("combat_exp",50000000);
        set_skill("literate",40);
        set_skill("cure",50);
        set_skill("magic",20);
        set_skill("spells",20);
        set_skill("shasword",200);
        set_skill("shaforce",280);
        set_skill("sha-steps",200);
        set_skill("sha-array",200); 
        set_skill("array",100);
        set_skill("move",280);
        set_skill("force",270);
        set_skill("dodge",280);
        set_skill("parry",220);
        set_skill("sword",220);
        map_skill("array","sha-array");
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("force","shaforce");
        map_skill("sword","shasword");

        setup();
        carry_object("/open/gsword/obj/dragon-sword.c")->wield();
}
int force_me(string cmd)
{
  return command( this_object()->process_input(cmd) );
}

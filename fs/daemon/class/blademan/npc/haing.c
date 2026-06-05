inherit NPC;
string do_ask (object me);
#include "/open/open.h"
#include <ansi.h>
void create()
{
set_name("離子寒", ({ "hiang",}) );
set("long", "
她是魔刀門首傳女弟子，明脈浩齒，一雙柳葉眉如遠山黛月般橫臥
天靈，晶盈的雙目被瞼水長睫所遮掩，眉目間一股靈秀之氣顯出智
慧的不凡，身上僅著一件浴袍，玲隴的身材若隱若現。\n");
set("title","魔刀首傳後三女弟子");
set("nickname", HIC + "清風雲裳" + NOR);
set("age", 25);
set("family/family_name","魔刀門");
set("int", 35);
set("m_blade",1);
set("cps", 35);
set("str", 35);
set("cor", 35);
set("spi", 35);
set("con", 35);
set("have_book",1);
set("kar", 35);
set("per", 35);
set("force_factor", 20);
set("combat_exp",1500000);
set("force", 4000);
set("max_force", 4000);
set("max_kee", 4000);
set("kee", 4000);
set("env/get_mblade","YES");
set("env/魔性六斬","YES");
set("mpower",1);
set("bellicosity", 2500);
set_skill("blade", 120);
set_skill("dodge", 105);
set_skill("parry", 105);
set_skill("force", 50);
set_skill("literate",105);
set_skill("dragon-blade", 120);
set_skill("powerforce", 95);
set_skill("unarmed", 50);
set_skill("move",50);
map_skill("force", "powerforce");
map_skill("parry", "dragon-blade");
map_skill("blade", "dragon-blade");
set("chat_chance_combat", 60);
set("chat_msg_combat", ({
(: perform_action, "blade.mdragon-dest" :),
}));
set( "gender", "女性");
set("limbs", ({ "頭部",  "雙腳", "雙手", "背部" ,"腹部","腰部"}) );     
set("attitude", "peaceful");
set("chat_chance", 2);
set("chat_msg", ({
"黎子寒疑惑的望著妳。 \n",
"黎子寒問到：『這位姑娘有事嗎 ...? 』\n",
}));
set("inquiry",([
"神兵利器" : "據我所知，當今的神兵利器，首推玉衡天劍和龍虎刀!\n",
"玉衡天劍" : "那是仙劍派開山祖師逍遙子的佩劍!\n",
"龍虎刀"   : "龍虎刀是金刀門至寶，始祖王蹇之佩刀!\n",
"刀塚":"相傳是一處藏滿絕世好刀的地方，不妨跟你說，聽說師祖莫測當年橫掃武林時，所用的刀就是從刀塚取出的，之後那把刀就成為魔刀鎮教之寶。\n",
"麒麟角" : "這個我也不太清楚,只大略曉得麒麟喜歡吃鳳凰蛋!\n",
"鳳凰蛋" : "聽說在高大的梧桐樹上居有這種奇獸!\n",
        ]));
set_temp("apply/armor",45);
set_temp("apply/damage",45);
     setup();
     carry_object("/daemon/class/blademan/obj/blade1.c")->wield();
     carry_object("/daemon/class/blademan/obj/cloth1.c")->wear();
     carry_object("/daemon/class/blademan/obj/belt1.c")->wear();
     add_money("gold",10);
}
 
void greeting(object ob)
{

           if( ob->query("gender")=="男性")
        {
         command("say 哼 ！ 大色狼 ， 我宰了你 ！" );
        kill_ob(ob);
   }   }
int accept_kill(object who)
{
  who=this_player();
  command("kill "+who->query("id"));
  command("perform blade.mdragon-dest");
  return 1;
}

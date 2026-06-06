//by sueplan 五儒生5
//會放lotch及會抓plan
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
int done=0;


void create() {
        set_name("夏侯仲淵",({"scholar houng","houng","scholar"}));
        set("class","scholar");
        set("nickname","$HIW$才高八斗$NOR$");
        set("title","五儒之尊");
        set("long",
        "\n，為儒門五儒生中上官知禮之師，以才智雙全
聞名，並且夏侯一派古自得儒門孔老夫子之弟子
子貢教之，門風穩建。\n");
        set("inquiry", ([
"子貢" : "祖師子貢為我一族之尊師, 承其它四儒生之大成, 對四大儒生所會的計謀瞭如指掌。必且習得諸葛神算, 可說什麼計謀都會!!",
        ]));
        set("str",40);
        set("cor",40);
        set("cps",40);
        set("gender","男性");
        set("attitude","heroism");
        set("family/family_name","儒門");
        set("quests/lotch","1");
        set("max_gin",20000);
        set("max_kee",18000);
        set("max_sen",20000);
        set("max_force",8000);
        set("age",93);
        set("force",8000);
        set("force_factor",20);
        set("combat_exp",8000000);
        set("score",9000000);
        set_skill("stabber",150);
        set_skill("dodge",150);
        set_skill("move",120);
        set_skill("parry",120);
        set_skill("knowpen",100);
        set_skill("god-plan",100);
        set_skill("plan",120);
        set_skill("force",200);
        set_skill("poetforce",150);
        set_skill("winter-steps",100);
        map_skill("plan","god-plan");
        map_skill("dodge","winter-steps");
        map_skill("move","winter-steps");
        map_skill("force","poetforce");
        map_skill("stabber","knowpen");
        map_skill("parry","knowpen");
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",100);

        set("functions/movedown/level",100);
        set("functions/finger/level",100);
set("chat_chance_combat", 100);
set("chat_msg_combat",({
(: perform_action("stabber.movedown") :),
(: perform_action("stabber.finger") :),
}));
        set("chat_chance",50);
        set("chat_msg",({
        }));
setup();
        carry_object("/open/scholar/room/newplan/obj/test");
         carry_object("/open/scholar/room/newplan/obj/pen")->wield();
        add_money("gold",50);
 }
void init()
{
add_action("do_action","",1);
        set_heart_beat(1);
}
int do_action(string str)
  {
        object who=this_player();
        if(str)
        {
        if(strsrch(str,"plan.speed")!=-1)
        {
          command("say 愚蠢呀!!難到你不知道奇襲之計是我所創的嗎?!\n");
          write("\n你見夏侯仲淵神態自若, 就破解了眼前的計謀!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.hole")!=-1)
        {
          command("say 敢在我面前挖陷阱??少賣弄這種小聰明了!!\n");
          write("\n你見夏侯仲淵神態自若, 就破解了眼前的計謀!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.empty")!=-1)
        {
          command("say 空城計?!你以為我會笨到這種地步嗎??\n");
          write("\n你見夏侯仲淵神態自若, 就破解了眼前的計謀!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.wait")!=-1)
        {
          command("say 想用伏兵玩我?!你以為我會笨到這種地步嗎??\n");
          write("\n你見夏侯仲淵神態自若, 就破解了眼前的計謀!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.rob")!=-1)
        {
          command("say 趁火打劫?!愚蠢!!難道你不知道此計為我所創嗎??\n");
          write("\n你見夏侯仲淵神態自若, 就破解了眼前的計謀!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.false")!=-1)
        {
          command("say 虛兵之計是最基本的計謀, 我會有不懂之理??\n");
          write("\n你見夏侯仲淵神態自若, 就破解了眼前的計謀!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.mount")!=-1)
        {
          command("say 想趕我走??你想得太美了吧!\n");
          write("\n你見夏侯仲淵神態自若, 就破解了眼前的計謀!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.lock-link")!=-1)
        {
          command("say 鐵鎖連環我研究的方法可比你多著呢!!敢對我用?\n");
          write("\n你見夏侯仲淵神態自若, 就破解了眼前的計謀!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.ghost")!=-1)
        {
          command("say 欺敵??我可不會笨到這種地步喔!!\n");
          write("\n你見夏侯仲淵神態自若, 就破解了眼前的計謀!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        }
return 0;
}
int accept_kill(object who,object me)
{
        who=this_player();
        me=this_object();
        command("wield pen");
        command("say 愚蠢!!你以為我會一個人對付你嗎?");
        command("kill "+who->query("id"));
        command("use lotch");
        command("use lotch");
        command("use lotch");
        command("use lotch");
        command("use lotch");
        command("use lotch");
        command("use lotch");
        command("use lotch");
        command("use lotch");
        me->add("sen",200);
        command("perform stabber.movedown");
        return 1;
}
int accept_fight(object who)
{
        who=this_player();
        command("say 如果不敢和我較量, 那就別來這邊送死!!");
          return 0;
}

void heart_beat()
{
        object ob=this_object();
        if( is_fighting() ){
        if(random(14) >9)
        {
message_vision(HIY"\n\n\n一陣氣勁劃過所有人，只見夏侯仲淵大喊 :『天地悠悠在我心』，使身上氣力恢復。\n\n\n"NOR,ob);
          ob->delete_busy();
        ob->add("kee",1000);
        ob->add("force",500);
          ob->receive_heal("gin",100);
          ob->receive_heal("sen",100);
        }
        }
        :: heart_beat();
}
void die()
{
object winner = query_temp("last_damage_from");
winner->set_temp("ko_houng",1);
:: die();
}

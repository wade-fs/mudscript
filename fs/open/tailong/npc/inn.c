#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string six_sp();
void create()
  {
        set("class", "scholar");
        set_name("本因", ({ "master inn", "master", "inn" }) );
        set("title","天龍寺第九任住持");
        set("nickname", HIR"劍氣沖天"NOR);
        set("gender", "男性");
        set("age", 200);
        set("attitude", "heroism");
        set("long",
        "你眼前正是大理段是的武學重鎮『天龍寺』的住持----本因大師, \n"
        "據說他六脈神劍早已練入化境, 當世能和他齊肩並論的, 只有其姪\n"
        "孫『段譽』, 不過百年來, 從未有人見識過他真正的武功\....\n");
        set("str", 48);
        set("cps", 40);
        set("per", 34);
        set("int", 38);
        set("kar", 16);
        set("combat_exp",2000000);
        set("max_kee",4500);
        set("kee",5000);
        set("force"       , 4000);
        set("max_force"   , 4000);
        set("force_factor", 30);
        set("score"       , 200000);
        set("s_kee",1000);
        set("marks/six_sp",3);
        set("max_s_kee",1000);
        set("sec_kee","god");
        set("inquiry",([
                 "段譽":"他現在與其妻王語嫣避居在此, 還望施主不要去擾他們\n",
                 "枯\榮大師":"大師現在正在苦參枯\榮禪, 據說是一門威力強的武功\\n",
                 "段延慶":"此人乃是我大理段氏最頭痛的人物, 不但武功\奇高, 為人亦十分冷靜沈著, 十分難纏\n",
                 "奧義":   (: six_sp :),
          ]));
        set("functions/handwriting/level",65);
       set("max_gin",5000);
       set("max_sen",5000);
       set("gin",5000);
       set("sen",5000);
       set_skill("cure",100);
       set_skill("move",80);
       set_skill("unarmed", 100);
       set_skill("force",150);
       set_skill("parry",100);
       set_skill("dodge",100);
       set_skill("literate",100);
       set_skill("linpo-steps",120);
       set_skill("six-fingers",120);
       set_skill("sunforce",150);
       map_skill("force", "sunforce");
       map_skill("unarmed", "six-fingers");
       map_skill("dodge", "linpo-steps");
       map_skill("parry", "six-fingers");
       map_skill("stabber", "six-fingers");
       set("chat_chance_combat",40);
       set("chat_msg_combat",({
            (: perform_action, "unarmed.handwriting"   :),
            (: "cmd god_kee"   :)
        }));
        create_family("段家", 5, "掌門人");
        setup();
//            carry_object(__DIR__"")->wear();
//            carry_object(__DIR__"")->wear();
//            carry_object(__DIR__"")->wear();
//            carry_object(__DIR__"")->wear();
//            carry_object(__DIR__"")->wear();
//            carry_object(__DIR__"")->wear();
//            carry_object(__DIR__"")->wear();
//            carry_object(__DIR__"")->wear();
//            carry_object(__DIR__"")->wield();
        add_money("gold",40);
}

int accept_object(object who, object ob)
{
  string name=who->query("name");
  if( ob->query("id") == "six book" && who->query_temp("six_sp_quest")==10)
  {
    destruct(ob);
    tell_object(users(),HIY"
                 本因方丈說道:"HIW"
                             「這次"HIG+name+HIW"為我天龍寺除去大患, 奪回寶經
                               老衲今日便將神劍奧義盡傳於你, 
                               望你今後斬妖除魔, 重振大理段氏的聲威!!」
"NOR);
    who->set("marks/six_sp",3);
    who->set("quest/4-badman",1);
    who->set("title",HIW"大理段氏絕代高手"NOR);
  }

else if( ob->query("id") == "tai mark" && who->query_temp("six_sp_quest")==8)
  {
    destruct(ob);
    say(HIY"本因大師說道:段延慶據說藏身在『狂風嶺』, 段雲既然派施主來, 想必有驚人藝業, 
             此事就相煩施主, 務必奪回六脈神劍經!!\n"NOR);
    say(HIY"本因大師又說:狂風嶺就在平南城西郊, 快去吧!!\n"NOR);
    who->set_temp("six_sp_quest",9);
  }
}
int accept_kill(object who)
{
 command("say 老衲逼不得已, 只有和施主走上幾招!\n");
 kill_ob(who);
 command("cmd god_kee");
 return 1;
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
     ::heart_beat();
}

string six_sp()
{
 object me;
 me=this_player();
 if(me->query_temp("six_sp_quest")!=9)
  {
   return "奧義乃是我派密奧, 不會輕易傳給弟子...\n";
  }
 say(HIY"本因大師道:你似乎並未得授神劍奧義, 我便傳你「奪命連環六絕劍」\n");
 say(HIY"           望你能憑此招奪回寶經!!\n");
 me->set("marks/six_sp",1);
 me->set("title","天龍寺俗家高手");
}

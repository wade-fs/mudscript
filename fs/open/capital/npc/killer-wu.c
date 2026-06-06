// 焚天魔王 by roger
// 焚天在修正 by chan
#include <ansi.h>
inherit NPC;   
void create()
{
        set("long","
莫無愁，天下第一黑道盟主，擅長暗殺，靠獎金為生!!!!!
接收各幫派委任!!若有被幫派追緝的人出現在他的面前!!!絕對是殺無赫!!!!
其武功\為極火功\及極火掌!!!來歷不祥!!!!
");
        set("gender","男性");
        set("class","fighter");
        set("nickname",HIR"極道殺手"NOR);
        set("title","黑道盟主");
        set_name("莫無愁",({"wu"}));
        set("combat_exp",15500000);
        set("attitude","hero");
        set("score",5000000);
        set("bellicosity",10000);
        set("age",45);
        set("max_force",250000);
        set("force",240000);
        set("max_kee",33000);
        set("kee",34000);
        set("max_gin",14000);
        set("max_sen",14000);
        set("str", 35);
        set("cor", 35);
set("no_lyssa",1);
        set("cps", 30);
        set("per", 30);
        set("int", 30);
        set("force_factor",45);
        set_skill("dodge",220);
        set_skill("force",250);
        set("clan_kill",1);     //不能派殺手追殺
        set_skill("move",280);
        set_skill("parry",250);
        set_skill("mogi-steps",200);
        set_skill("firestrike",220);
        set_skill("unarmed",220);
        set_skill("literate",200);
        set_skill("fireforce",250);
        set_temp("armor_vs_force",5000);
        map_skill("force","fireforce");
        map_skill("unarmed","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("parry","firestrike");
        set("functions/gold-fire/level",100);
        set("quest/gold-fire",1);
        set("quest/new_gold_fire",1);
        setup();
        carry_object("/autoload/mogi/fire-armor")->wear();
        carry_object("/autoload/mogi/fire-cloud-boots")->wear();
        carry_object("/autoload/mogi/fire-belt")->wear();
        carry_object("/autoload/mogi/daemon-cloak")->wear();
        carry_object("/autoload/mogi/fire-dragon")->wield();
        add_money("gold",1000);
}

void greeting(object ob)
{
 if(ob->query("ckill"))
  {
    command("say 哈!!哈!!又一個來送死的!!看掌!!");
    command("perform fireforce.gold-fire");
    kill_ob(ob);
    ob->start_busy(2);
  } else if(ob->query("mk-blade")) {
if(ob->query("gender")=="男性") {
if(ob->query("title")!="漩羽刀皇" && !ob->query_temp("powerup") &&
   !ob->query_temp("addbasic")) {
tell_object(ob,HIW"你使用邪靈制刀術錯亂，我幫你還原title\n"NOR);
ob->set("title","漩羽刀皇"); }} else {
if(ob->query("title")!="刀魂幽姬" && !ob->query_temp("powerup") &&
   !ob->query_temp("addbasic")) {
tell_object(ob,HIW"你使用邪靈制刀術錯亂，我幫你還原title\n"NOR);
ob->set("title","刀魂幽姬"); }}}
}

// sell_officer.c
#include <ansi.h>
inherit NPC;
void create()
  {
        set("class", "officer");
        set_name("吳總管", ({ "officer wu", "officer"}) );
        set("title","朝庭命官");
        set("nickname", "龍圖閣大學士");
        set("gender", "男性");
        set("age", 45);
        set("clan_kill",1);
        set("attitude", "hero");
        set("long",
        "吳總管為朝庭中龍圖閣大學士，其學識為武林、文譠中第一等的人材\n");
       set("str", 48);
       set("cps", 40);
       set("per", 34);
       set("int", 38);
       set("kar", 16);
       set("fire_strike",1);
       set("super_fire",1);
       set("combat_exp",5000000);
       set("max_kee",9500);
       set("kee",12000);
       set("force"       , 6000);
       set("max_force"   , 7000);
       set("force_factor", 40);
       set("score"       , 200000);
       set("s_kee",400);
       set("env/狂擊","YES");
       set("max_s_kee",1000);
       set("sec_kee","tiger");
       set("functions/kang_kee/level",100);
       set("max_gin",5000);
       set("max_sen",5000);
       set("gin",5000);
       set("sen",5000);
       set_skill("cure",40);
       set_skill("move",50);
       set_skill("unarmed", 120);
       set_skill("force",120);
       set_skill("parry",50);
       set_skill("dodge",50);
       set_skill("fire-kee",100);
        set_skill("literate",40);
        set_skill("henma-steps",100);
        set_skill("literate",30);
        set_skill("lungshan",100);
        set_skill("haoforce",100);
        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
        map_skill("dodge", "henma-steps");
        map_skill("parry", "fire-kee");
        set("chat_chance_combat",65);
        set("chat_msg_combat",({
            (: perform_action, "force.kang_kee"   :),
        }));
        setup();
        add_money("gold",20);
}

int accept_object(object who, object ob)
{
  object mid;
  string head_name;
  head_name=ob->query("id");
  switch(head_name)  {
  case "fire-king-head":
       command("cong");
       command("say 這是!!這是!!朝庭第一賞金的焚天魔王的人頭!!!");
       command("say 大俠真是武功\高強!!!!這是7500兩的賞金請收下!!!\n");
    mid=new("/obj/money/cash");
       mid->set_amount(75);
       mid->move(who);
       break;
  case "dragon-head":
       command("cong");
       command("say 這是!!這是!!朝庭第一賞金的黃金甲龍的龍頭!!!");
       command("say 大俠真是武功\高強!!!!這是650兩的賞金請收下!!!\n");
    mid=new("/obj/money/gold");
       mid->set_amount(650);
       mid->move(who);
       break;
  case "black-ghost-head":
       command("cong");
       command("say 這是!!這是!!魔界黑白雙剎的人頭!!!\n");
       command("say 大俠真是武功\高強!!!!這是600兩的賞金請收下!!!\n");
    mid=new("/obj/money/cash");
       mid->set_amount(6);
       mid->move(who);
       break;
  case "white-ghost-head":
       command("cong");
       command("say 這是!!這是!!魔界黑白雙剎的人頭!!!\n");
       command("say 大俠真是武功\高強!!!!這是600兩的賞金請收下!!!\n");
    mid=new("/obj/money/cash");
       mid->set_amount(6);
       mid->move(who);
       break;
  case "seven-dark-head":
       command("cong");
       command("say 這是!!這是!!魔界七魔將的人頭!!!\n");
       command("say 大俠真是武功\高強!!!!這是500兩的賞金請收下!!!\n");
    mid=new("/obj/money/cash");
       mid->set_amount(5);
       mid->move(who);
       break;
  case "mechoufen-head":
       command("cong");
       command("say 這是!!這是!!黑風雙剎之梅超風的人頭!!!\n");
       command("say 大俠真是武功\高強!!!!這是130兩的賞金請收下!!!\n");
    mid=new("/obj/money/gold");
       mid->set_amount(130);
       mid->move(who);
       break;
  case "lin-head":
       command("cong");
       command("say 這是!!這是!!聖火教主之林宏昇的人頭!!!\n");
       command("say 大俠真是武功\高強!!!!這是750兩的賞金請收下!!!\n");
    mid=new("/obj/money/gold");
       mid->set_amount(750);
       mid->move(who);
       break;
  case "sa-head":
       command("cong");
       command("say 這是!!這是!!大魔頭獨孤嵊的人頭!!!\n");
       command("say 大俠真是武功\高強!!!!這是750兩的賞金請收下!!!\n");
    mid=new("/obj/money/gold");
       mid->set_amount(750);
       mid->move(who);
       break;
  case "tiger-head":
       command("cong");
       command("say 這是!!這是!!平南城獨角獸的獸頭!!!\n");
       command("say 大俠真是武功\高強!!!!這是10兩的賞金請收下!!!\n");
       mid=new("/obj/money/gold");
       mid->set_amount(10);
       mid->move(who);
       break;
  case "zhang-z-head":
       command("cong");
       command("say 這是!!這是!!風林三頭目張繼的人頭!!!\n");
       command("say 大俠真是武功\高強!!!!這是40兩的賞金請收下!!!\n");
    mid=new("/obj/money/gold");
       mid->set_amount(40);
       mid->move(who);
       break;
  case "liu-head":
       command("cong");
       command("say 這是!!這是!!風林二頭目劉信的人頭!!!\n");
       command("say 大俠真是武功\高強!!!!這是60兩的賞金請收下!!!\n");
    mid=new("/obj/money/gold");
       mid->set_amount(60);
       mid->move(who);
       break;
  case "ra-head":
       command("cong");
       command("say 這是!!這是!!風林大頭目雷霸的人頭!!!\n");
       command("say 大俠真是武功\高強!!!!這是200兩的賞金請收下!!!\n");
    mid=new("/obj/money/cash");
       mid->set_amount(2);
       mid->move(who);
       break;
  case "master-snake-head":
       command("cong");
       command("say 這是!!這是!!蛇寨寨主蛇郎君的人頭!!!\n");
       command("say 大俠真是武功\高強!!!!這是3000兩的賞金請收下!!!\n");
    mid=new("/obj/money/cash");
       mid->set_amount(30);
       mid->move(who);
       break;
  default :
       command("say 不想活了呀!!竟欺騙朝庭命官呀!!!給我滾!!!!\n");
       break;
  }
log_file("mblade/sell_head",sprintf("%s(%s) 賣了 %s\n",who->query("name"),who->query("id"),ob->query("id")));
       destruct(ob);
       return 1;
}

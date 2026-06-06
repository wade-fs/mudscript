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
            (: "cmd god_kee"   :)
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
       command("say 大俠真是武功高強!!!!這是25000兩的賞金請收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(2500);
       mid->move(who);
       break;
  case "dragon-head":
       command("cong");
       command("say 這是!!這是!!朝庭第一賞金的黃金甲龍的龍頭!!!");
       command("say 大俠真是武功高強!!!!這是6500兩的賞金請收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(650);
       mid->move(who);
       break;
  case "black-ghost-head":
       command("cong");
       command("say 這是!!這是!!魔界黑白雙剎的人頭!!!\n");
       command("say 大俠真是武功高強!!!!這是6000兩的賞金請收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(600);
       mid->move(who);
       break;
  case "white-ghost-head":
       command("cong");
       command("say 這是!!這是!!魔界黑白雙剎的人頭!!!\n");
       command("say 大俠真是武功高強!!!!這是6000兩的賞金請收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(600);
       mid->move(who);
       break;
  case "seven-dark-head":
       command("cong");
       command("say 這是!!這是!!魔界七魔將的人頭!!!\n");
       command("say 大俠真是武功高強!!!!這是5000兩的賞金請收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(500);
       mid->move(who);
       break;
  case "ya-head":
       command("cong");
       command("say 這是!!這是!!大魔頭葉狂的人頭!!!\n");
       command("say 大俠真是武功高強!!!!這是5000兩的賞金請收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(500);
       mid->move(who);
       break;
  case "sa-head":
       command("cong");
       command("say 這是!!這是!!大魔頭獨孤嵊的人頭!!!\n");
       command("say 大俠真是武功高強!!!!這是7500兩的賞金請收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(750);
       mid->move(who);
       break;
  case "tiger-head":
       command("cong");
       command("say 這是!!這是!!平南城獨角獸的獸頭!!!\n");
       command("say 大俠真是武功高強!!!!這是10兩的賞金請收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(10);
       mid->move(who);
       break;
  case "zhang-z-head":
       command("cong");
       command("say 這是!!這是!!風林三頭目張繼的人頭!!!\n");
       command("say 大俠真是武功高強!!!!這是400兩的賞金請收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(40);
       mid->move(who);
       break;
  case "liu-head":
       command("cong");
       command("say 這是!!這是!!風林二頭目劉信的人頭!!!\n");
       command("say 大俠真是武功高強!!!!這是600兩的賞金請收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(60);
       mid->move(who);
       break;
  case "ra-head":
       command("cong");
       command("say 這是!!這是!!風林大頭目雷霸的人頭!!!\n");
       command("say 大俠真是武功高強!!!!這是900兩的賞金請收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(90);
       mid->move(who);
       break;
  default :
       command("say 不想活了呀!!竟欺騙朝庭命官呀!!!給我滾!!!!\n");
       break;
  }
       destruct(ob);
       return 1;
}

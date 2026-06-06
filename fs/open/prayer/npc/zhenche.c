#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

object ob1=this_object();
int have_say;

void create()
{
set_name("簫揚", ({"shin young","shin","young"}));
set("gender","男性");
set("age",30);
set("class","prayer");
set("family/master_name","林宏昇");
set("nickname","智慧之星");
set("attitude","heroism");
set("long",@LONG
    此人乃是陣勢門門主,他身上流著西域人和中原人的血統,
    剛踏入聖火教就被聖火教軍師駱芝芝欣賞,駱芝芝並把一
    生所學的謀略和武學傳授給簫揚,讓聖火教有人繼軍師的
    的職位,他因為先天的聰明和後天的教導,使他幾乎超過駱
    芝芝,神機妙算,料事如神,使他被各大長老和門主教徒稱
    為[智慧之星],因而如此被教皇封他為[陣勢門]門主。

LONG);

set("combat_exp",1000000);
set("title","陣勢門主");
set("kee",6200);
set("max_kee",6200);
set("force",9000);
set("max_force",9000);
set("max_gin",4000);
set("max_sen",4000);
set("force_factor",5);
set_skill("canon",80);
set_skill("holy-force", 70);
set_skill("superforce", 80);
set_skill("cure", 50);
set_skill("dodge", 70);
set_skill("force", 70);
set_skill("move",70);
set_skill("parry", 70);
set_skill("unarmed", 70);
set_skill("literate", 90);
set_skill("shift-steps",70);
set_skill("universe", 80);
map_skill("force","superforce");
map_skill("dodge","shift-steps");
map_skill("move","shift-steps");
map_skill("parry","universe");
map_skill("unarmed","universe");
set("chat_chance",5);
set("chat_msg",({
HIW+"簫揚說道：兵者，國之大事，生死之地，存亡之道，不可不察也。\n"+NOR,}));

setup();

carry_object("/open/prayer/obj/emery-robe")->wear();
carry_object("/open/prayer/obj/hat")->wear();
carry_object("/open/prayer/obj/emery-armband")->wear();
carry_object("/open/prayer/obj/emery-belt")->wear();
carry_object("/open/prayer/obj/emery-firer")->wield();
add_money("gold",5);

create_family("陣勢門",5,"門主");
}

void attempt_apprentice(object ob)
{
    if(!ob->query_temp("allow_8"))
  { command("say 沒有教主的同意，我不敢擅自做主讓你進門！");
    return 0;
  }
  command("smile");
  command("say 進入陣勢門之後，你就必需對本教忠心不二，不可懷有私心！知道嗎！！");
  command("recruit "+ob->query("id"));
  ob->set("marks/聖火八天門",1);
  this_player()->set("title","聖火教陣勢門俗家弟子");
}
void greeting(object ob)
{
  if (ob->query_skill("poison",1))
//if ((present("five poison", ob)) || (present("drak poison",ob)) || (present("faint poison", ob)) || (present("rose poison", ob)))
  {
   command("say 教主有令！！凡是學有毒術之人，殺無敕！！");
   kill_ob(ob);
  }
   if(ob->query("class") == "dancer" )
     {
      command("say 教主有令，見到舞者----格殺勿論！！");
      kill_ob(ob);
     }
   return;
}

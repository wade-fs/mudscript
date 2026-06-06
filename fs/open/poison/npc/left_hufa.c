#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
	set_name("左護法",({"left hufa","hufa"}));
	set("title","冥蠱魔教護法");
	set("gender","男性");
	set("class","poisoner");
	set("age",26);
		set("str",40);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
	set("force",500);
	set("max_force",500);
	set("combat_exp",20564);
	set_skill("dodge",30);
	set_skill("unarmed",30);
	set_skill("nine-steps",45);
	set_skill("poison",20);
	set_skill("coldpoison",20);
	map_skill("dodge","nine-steps");
	map_skill("poison","coldpoison");
	set_skill("parry",20);
	setup();
carry_object("/obj/poison/rose_poison")->set_amount(5);
carry_object("/obj/poison/five_poison")->set_amount(5);
carry_object("/obj/poison/dark_poison")->set_amount(5);
carry_object("/obj/poison/faint_poison")->set_amount(5);

}

int accept_object(object me,object ob)
{
      if(ob->query("id")=="moon stone")
        if(me->query("class")=="poisoner")
      {
      me->set("mark/love",1);
      message_vision("左護法對你笑了笑。\n",me);
     command("say 恭喜你，你有資格修行本門鎮教絕學「傾城之戀(forever-love)」了。");
      command("say 快去右護法所陣守的密室吧。");
      me->set("title","傾城之戀傳人");
        }
     else
     {
        command("smile "+me->query("id"));
     command("say 多謝你找回月石");
      }
}

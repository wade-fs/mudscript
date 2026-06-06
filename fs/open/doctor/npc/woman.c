#include <ansi.h>
inherit NPC;

void create()
{
  set_name("老婦人", ({"old woman","woman"}) );
  set("title",HIR"焦急無助"NOR);
  set("long", "一個焦急無助的老婦人。\n");
  set("gender", "女性");
  set("age", 73);
  set("attitude", "peaceful");
  set("chat_chance", 4);
  set("chat_msg", ({
    "老婦人焦急的走來走去，一臉悲傷的樣子！\n",
  }));
  setup();
}

void init()
{
  object me=this_player();
  ::init();

  if(interactive(me) && !is_fighting())
  {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  }
  add_action("do_say","say");
}

int do_say(string arg)
{
  object me=this_player();

  if(!me->query("doctor/save_die") && !me->query("doctor/agree_woman") && (int)me->query("combat_exp") >= 2000000)
  {
    if( arg == "好" )
    {
      command("wa "+me->query("id"));
      command("say 真是太感謝您了，我兒子得的是種怪病，麻煩你看看(check)他！");
      me->set("doctor/agree_woman", 1);
      return 1;
    }
    if( arg == "不好" )
    {
      command("sigh "+me->query("id"));
      command("say 你真是個無人性的醫生......");
      return 1;
    }
  }
  if(me->query("doctor/check_man")==1)
  {
    if( arg == "情況似乎不太妙" ) //將情況似乎不太樂觀改為情況似乎不太妙 是因為zmud會吃字 算是福利玩家吧（攤
    {
      write("你告訴老婦人，病人的情況似乎不太妙...\n"NOR);
      command("nod "+me->query("id"));
      command("say 華神醫也是這樣說的，但神醫好像有提到什麼「不傳之技」之類的...");
      command("say 要是可以找到有人擁有這樣能力的人，該有多好...");
      command("sigh");
      me->delete("doctor/check_man");
      me->set("doctor/tell_woman", 1);
      return 1;
    }
  }
}

void greeting(object me)
{
  if(!present("young man",environment(this_object()))) {
    write(HIY"老婦人眼見兒子沒救，忽然大吼一聲﹕我兒呀……\n"NOR,me);
    this_object()->die();
    return;
  }
  if(me->query("doctor/agree_woman")==1)
  {
    command("say 麻煩您快看看我的兒子ㄚ！");
  }
  else if(me->query("class")=="doctor" && !me->query("doctor/save_die"))
  {
    write(HIY"老婦人緊緊握著你的手，一臉哀傷的望著你！\n"NOR);
    write(HIY"老婦人哭道：這位神醫，請您救救我的孩子好不好？！\n"NOR);
    command("sob "+me->query("id"));
  }
  else if(me->query("doctor/save_die")==1 && !me->query("doctor/save_die_gift"))
  {
    write(HIY"老婦人緊緊握著你的手，一臉哀傷的望著你！\n"NOR);
    write(HIY"老婦人哭道：這位神醫，既然你已經學會了，就請您救救我的孩子好嗎？！\n"NOR);
    command("bow "+me->query("id"));
  }
  else if(me->query("doctor/save_die")==1)
  {
    command("smile "+me->query("id"));
  }
  else
  {
    command("sigh");
    command("say 唉！你是幫不上忙的...");
  }
}

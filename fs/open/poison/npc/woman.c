
// by lys
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string want_help(object me);
void create()
{
        set_name("趙大娘", ({ "old woman","woman" }) );
        set("long","趙大娘看起來非常難過，不知到有何傷心事。\n");
        set("gender","女性");
        set("age",60);
        set("int",45);
        set("inquiry", ([
                "傷心事" : "唉 ! 我兒子不知為何被人抓走了。\n",
                "被誰抓走": "唉 ! 我想應該就是被冥蠱魔教的教徒捉去。\n",
                "兒子"   : (: want_help :) ,
                "趙青雲" : "他就是我的心肝寶貝呀。\n",
                ]) );
        setup();
}
void init()
{
  remove_call_out("greets");
  call_out("greets",1,this_player());
  add_action("do_nod","nod");
  add_action("do_shake","shake");
  add_action("do_say","say");
}
void greets(object me)
{
  command("sigh");
}

string want_help(object who)
{
        object me = this_player();
        object room = environment(this_object());
        me->set_temp("poison_help",1);
	command("say 我兒子就是英俊瀟灑的趙青雲。");
	command("say "+me->query("name")+"你可以幫我找回我的兒子嗎? ");
        return "唉～～可憐可憐我這個老婦人吧!!" ;
}
int do_nod()
{
object me = this_player();
if(me->query_temp("poison_help") != 1)
        return 0;
me->set_temp("poison_help",2);
remove_call_out("greeting");
call_out("greeting",1,me);
 return 0;
}
int do_say(string str)
{
object me = this_player();
if(me->query_temp("poison_help") != 1)
        return 0;
if(str == "yes" || str == "可以")
     {
	me->set_temp("poison_help",2);
        remove_call_out("greeting");
        call_out("greeting",1,me);
        return 0;
     }
delete_temp("poison_help");
remove_call_out("greeting2");
call_out("greeting2",1,me);
return 0;
}
int do_shake()
{
  object me = this_player();
  if(me->query_temp("poison_help") != 1)
        return 0;
  me->delete_temp("poison_help");
  remove_call_out("greeting2");
  call_out("greeting2",1,me);
  return 0;
}
void greeting(object me)
{
  object ob = this_object();
  command("smile");
  command("say 謝謝你肯幫我忙，我就在此等你和我兒子的消息。");
}
void greeting2(object me)
{
command("sigh");
tell_room(environment(this_object()),HIC"只見老婦轉身向外望去，癡癡等待兒子歸來
。\n"NOR);
}
int accept_fight(object who)
{
 object me = this_player();
 command("help!");
 command("say 哇! "+me->name()+"要欺負我這孤苦的老人。");
  return notify_fail(HIC"趙大娘忙道﹕"NOR+me->name()+"請放過我這可憐的老婦人吧。\n");
}
int accept_object(object who, object item)
{
 if(item->query("id") == "jade")
   {

        destruct(item);
        command("say 這是我給青雲的玉珮\沒錯。");
        command("say 看來你已經找到我兒子了。");
        command("say 謝謝你的幫忙。");
  if(!who->query("quests/poison_help") && who->query_temp("poison_help")==4)
          {
	    who->add("combat_exp",800);
            tell_object(who,HIY"你完成了『老婦人的傷心事』任務！\n"NOR);
            tell_object(who,HIC"你的經驗增加了！\n"NOR);
            who->set("quests/poison_help", 1);
            return 1;
          }
  return 1;

   }
}

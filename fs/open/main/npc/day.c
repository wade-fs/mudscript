#include <ansi.h>
#include "/open/open.h"

inherit NPC;

string do_ask ();

void create()
{
        seteuid(getuid());
        set_name("燕南天", ({ "day" }) );
        set("nickname","天下第一神劍");
        set("gender", "男性" );
        set("age", 32);
        set_weight (500);
        set("long", @LONG
LONG);

        set("chat_chance", 3);
        set("chat_msg", ({
        }) );
        set("inquiry", ([
            "哭楓坡":   "我來這兒是為了跟我義弟江楓碰頭的。",
            "水仙姑娘": (: do_ask :),
            "江楓":     (: do_ask :),
        ]) );
        set("combat_exp",339);
        setup();
        carry_object(MAIN_OBJ"sword")->wield();
}

string do_ask ()
{
  object        me=this_player();
  int           query;

  query = me->query_temp("quests/help_water_god");
  if (query && query == 3) {
    me->set_temp("quests/help_water_god",4);
    call_out("gone", 1, me);
    return "啊，明明約好在這兒見面，難道出事了? " +
        "或者是...\n燕南天想了想, 說道: 我再去找他的書僮江琴問問看。";
  }
  else return "您有看到他們倆嗎? 如果有的話麻煩您通知我一聲。";
}

void gone(object me)
{
  tell_object(me, "燕南天告訴你: 我去找江琴的下落囉, bye bye.\n");
  destruct(this_object());
}

int accept_fight(object me)
{
  return notify_fail("燕南天說道: "+me->name()+
        "，我正在想辦法解救我那義弟江楓，沒空跟你囉唆。\n");
}
// 因為系統常出問題 而使day毒不死 所以把下面取消
/*
int accept_kill(object me)
{
  message_vision(HIR""+me->query("name")+"，這是你自找死路，可別怪我。\n"+
        "突然，燕南天拔出手中的長劍一揮，就在那一瞬間.....\n"+
        "$N感覺自己飛了起來，滿天星空一片血紅....\n"+
        "......那......不正是$N的身體嗎?....\n"NOR, me);
  me->die();
  return notify_fail("");
}
*/

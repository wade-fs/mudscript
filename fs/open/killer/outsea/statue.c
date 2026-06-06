inherit NPC;
#include <ansi.h>
string trouble();
void create()
{
set_name("海坊老",({"sea-god man","man","god"}));
set("long","管理著通往東瀛的海神，老態龍鍾，一臉憂鬱的樣子，
看來似乎遇到了一些麻煩。");
set("age",1000);
set("inquiry",([
"麻煩":(:trouble:),
]));
setup();
}
int accept_fight(object me)
{
me=this_player();
command("pat "+me->query("id"));
command("say 孩子，不要這麼衝動，你殺了我，你就出不去了。");
command("smile");
return 0;
}
int accept_kill(object me)
{
me=this_player();
command("pat "+me->query("id"));
command("say 孩子，不要這麼衝動，你殺了我，你就出不去了。");
command("smile");
return 0;
}
string trouble()
{
object me;
me=this_player();
if(me->query_temp("put_water")!=1)
{
command("sigh");
call_out("help01",1,me);
return "其實是這樣的....\n";
}
else
{
command("smile");
command("say 謝謝你把定水珠找回來。");
message_vision("海坊老手一揮，$N從這間房間消失了。\n",me);
me->move(__DIR__"sea01");
return HIY"呵呵...我會用定水珠的能力保護你的\n"NOR;
}
}
int help01(object me)
{
command("say 在前幾天，我不小心把雕像的定水珠搞丟了...唉唉...\n");
return 1;
}
int accept_object(object me,object ob)
{
me=this_player();
if(ob->query("id")!="static_water")
command("say 我要的是定水珠....@#$%");
else
{
command("say 真是太好了！謝謝你把定水珠找回來。");
call_out("help02",1,me);
}
}
int help02(object me)
{
message_vision("海坊老緩緩的走向雕像。\n",me);
call_out("help03",3,me);
return 1;
}
int help03(object me)
{
message_vision("海坊老拿起了$N給的定水珠，把定水珠裝進了雕像內。\n",me);
message_vision("緊接著一陣晃動，$N從這間房間消失了。\n",me);
me->move(__DIR__"sea01");
tell_object(me,HIY"海坊老用千里傳音跟你說：呵呵...我會用定水珠的能力保護你的\n"NOR);
call_out("time",1,me);
return 1;
}
int time(object me)
{
me->set_temp("put_water",1);
message_vision(HIB"$N的體內似乎散發著藍光。\n"NOR,me);
//tell_object(me,HIW"(你有十分鐘的時間受到定水珠的保護。)\n"NOR);
//call_out("timeout",600,me);
return 1;
}
int timeout(object me)
{
me->delete_temp("put_water");
tell_object(me,HIW"定水珠的能力失效了。"NOR);
message_vision(HIR"$N身體上的藍光漸漸退去。\n"NOR,me);
return 1;
}

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
set("short","仙境靈池");
set("long", @LONG
崑崙山中的聚靈聖地，眼前池水綠波盪漾，四周靈氣裊裊上升，
一座石椅上流露出陣陣彩霞，一幅綠光環繞的骨骸盤坐其中，令你不
知覺的想對它膜拜(pray)起來。

                陸皓雲的骨骸 (Skeleton)

LONG);

        set("light_up", 1);
        set("light", 1);
        set("no_chome", 1);
        set("no_fanset", 1);
        set("exits", ([ /* sizeof() == 1 */
        "south" : "/open/tendo/room/b1",
        ]));
        setup();

}

void init()
{
  add_action("do_pray", "pray");
}

int do_pray(string str)
{
  object me = this_player();

  if(!str || str != "skeleton" || me->query("quest/have_hawk")==1 ){
    return notify_fail("你想拜誰啊？\n");
    return 1;
  }
  me->set("quest/have_hawk",1);
  tell_object(me,HIY + "妳雙膝跪地，虔誠的對著陸皓雲的骨骸膜拜起來。\n" + HIG + "忽然間一道細微的聲音傳進你的耳朵。\n" + HIR + "吾..早知....時日無多.......\n只是...除魔大業....未..成\n天下...未能太平..\n今留下...靈鷹於此\n盼....有緣人..得以....收服\n除魔衛道....保天下...之..太平...\n則吾雖立於...九泉之下\n其心..亦安......\n" + NOR);
  tell_object(users(),HIW + "
         陸清風" + HIG + "大笑:"+HIB+this_player()->query("family/family_name")+HIG + "弟子"+HIB+this_player()->query("name")+HIG+"收服祖師爺所飼養的靈鷹了！\n\n
              " + HBCYN + "一聲長嘯劃破天穹。\n" + NOR);
  tell_object(me,"\n\t指令：cast waken於戰鬥中使用之。\n");
  return 1;
}

#include <ansi.h>
void init()
{
	add_action("do_hide","hide");
}
int do_hide(string arg)
{
  object me = this_player();
  me->set_temp("hide",1);
  write(HIG + "你躲在草叢裡試圖自身蹤跡。\n" + NOR);
  return 1;
}
int valid_leave(object me,string path)
{
    me->delete_temp("hide");
	write(HIR + "你離開草叢現了蹤跡。\n" + NOR);
	return 1;
}

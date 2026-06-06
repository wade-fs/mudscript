#include <ansi.h>
void heart_beat()
{
	if(this_object()->is_fighting())
	{
		message_vision(HIW"$N被戰鬥中的內力牽連到，完全無法抵抗，真氣從體內破體而出。\n"NOR,this_object());
		this_object()->die();
		return ;
	}
}
void die()
{
  object room = load_object("/open/shinyang/5-6");
  room->add_victim(this_object());
  room->die_for_direct(this_object());
  :: die();
}

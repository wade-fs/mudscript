// snake.c by powell

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("蛇群", ({ "snake" }) );
	set("race", "野獸");
	set("greeting_msg", ({
		"\n\n突然，你發現眼前是一群正慢慢蠕動的蛇群!\n"+
                "這些蛇身上都有鮮豔的色彩，想必都含有劇毒。\n"+
                "你唯一的念頭就是趕快離開這兒....\n\n\n\n\n"+
                HIR + "哇! 你被這群蛇咬了一口。\n\n"NOR+
                HIB + "蛇群開始四散而去.....\n" + NOR }) );
        this_player()->apply_condition("snake_poison", 10);
        call_out("gone",1); 
	setup();
}
void gone()
{
	destruct(this_object());
}

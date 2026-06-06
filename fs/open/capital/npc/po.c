inherit NPC;

void create()
{
	set_name("媒婆",({"po"}));
	set("long", "她是這次婚禮的媒婆，看她口開眉笑的樣子，"
		    "似乎拿了不少紅包哩。\n");
	set("age",50);
	set("gender","女性");
	set("no_kill",1);
	setup();
}

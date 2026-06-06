inherit NPC;

void create()
{
	set_name("俊馬",({"horse"}));
	set("short", "俊馬");
	set("race", "野獸");
	set("light_up",1);
	set("no_kill",1);
	setup();
}

void init()
{
  add_action("do_look", "look");
}

int do_look (string arg)
{
  object	me, env;

  me = this_player();
  if (!arg || arg != "out") return 0;

  env = environment();

  "/cmds/usr/look"->look_room(me, env, 1);
  return 1;
}

int start_marry(object husband)
{
  string	name=husband->query("name");

  set("short", "新郎官"+name+"的俊馬(Horse)");
  set("long", "這是一匹高大挺俊的馬匹，身上到處都結滿紅絲帶，顯得喜氣洋洋\n"+
              "的樣子，現在在上面坐著的正是新郎官--"+name+"。\n");
}

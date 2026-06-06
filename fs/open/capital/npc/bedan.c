inherit NPC;

void create()
{
	set_name("花轎",({"bedan"}));
	set("short", "花轎");
	set("race", "野獸");
	set("gender", "中性");
	set("light_up",1);
	set("age", 10);
	setup();
}

void init()
{
  add_action("do_look", "look");
}

int do_look (string arg)
{
  object        me, env;

  me = this_player();
  if (!arg || arg != "out") return 0;

  env = environment();

  "/cmds/usr/look"->look_room(me, env, 1);
  return 1;
}

int start_marry(object wife)
{
  string	name=wife->query("name");

  set("short", "美嬌娘"+name+"的花轎(Bedan)");
  set("long", "這是一頂花轎，上頭處處結紅采，顯得喜氣洋洋的樣子，\n"+
              "現在在裡面坐著的正是新娘--"+name+"。\n");
}

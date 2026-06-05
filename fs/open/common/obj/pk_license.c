// token.c

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
	set_name("ＰＫ執照", ({ "pk license", "license" }) );
	set("unit", "個");
	set ("no_get", 1);
	set ("no_drop", 1);
	seteuid(getuid());
	setup();
}

void init()
{
  add_action ("do_give", "give");
}

string long()
{
  return @TEXT
    擁有ＰＫ執照的人才能合法的享受ＰＫ的樂趣而不必擔心受
九省總巡捕的追殺，當然，別以為有了ＰＫ執照就可以為所欲為
的幹壞事，想ＰＫ還是去找同樣有ＰＫ執照的人吧！
    一旦你擁有ＰＫ執照，quit 之後仍然還在，下次 login 不
必再申請。如果想做安份的老百姓，可以在碰到九天巡捕的時候
向他懺悔退還執照，遺失視同無照，不得申請補發。
TEXT;
}

int query_autoload ()
{
  return 1;
}

int do_give(string arg)
{
  object	me, who, env, obj;
  string	something, someone;

  if (!arg || sscanf (arg, "%s to %s", something, someone) != 2)
    return notify_fail ("用法: give <某物> to <某人>\n");

  me = this_player();
  env = environment(me);
  obj = this_object();
  if (!who=present(someone, env))
    return notify_fail ("嘿! 你想給誰啊!!\n");
  if (something != "license" && something != "pk license") return 0;
  if (who->query("id") != "cop head")
    return notify_fail ("ＰＫ執照只能給九省總巡捕，不然就必須好好收藏。\n");
  message_vision("%N把ＰＫ執照交給了九省總巡捕。\n", me);
  return who->accept_object(me, obj);
}

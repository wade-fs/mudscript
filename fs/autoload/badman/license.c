inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
	set_name("超級壞蛋執照", ({ "badman license", "license" }) );
	set("unit", "張");
	set ("no_get", 1);
	set ("no_drop", 1);
	setup();
}

string long()
{
  return @TEXT
    擁有壞蛋證明的人才能順利的進入惡人谷而不受到騷擾。
TEXT;
}

int query_autoload ()
{
  return 1;
}

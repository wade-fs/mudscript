// copy from Room: /d/snow/postoffice.c

inherit ROOM;
		
void create ()
{
  set ("short", "大通驛站");
  set ("long", @LONG
位在永安胡同的中心，近鎮南門，是個開驛站的絕佳地
點，你不禁佩服老板的生意眼光。旁邊幾條長板凳還有幾張
木桌，想必是給長途跋涉的信差們休息用的。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r30",
]));

  set("light_up", 1);

  setup();
}

int valid_leave(object me, string dir)
{
        object mbox;

        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "你將信箱交回驛站。\n");
                destruct(mbox);
        }
        return 1;
}

void init()
{
  object mbox;

  seteuid(getuid());

  if( !this_player()->query_temp("mbox_ob") ) {
    mbox = new(MAILBOX_OB);
    if (mbox->move(this_player()))
      write ("驛站夥計看見你進來就交給你一個信箱。\n");
  }

  add_action ("do_home", "home");
  add_action ("do_goto", "goto");
}


int do_home(string arg)
{
  object mbox, me;

  me = this_player();
  if( mbox = me->query_temp("mbox_ob") ) {
    tell_object(me, "你將信箱交回驛站。\n");
    destruct(mbox);
  }
  
  return 0;
}

int do_goto (string arg)
{
  object mbox, me;

  me = this_player();
  if( mbox = me->query_temp("mbox_ob") ) {
    tell_object(me, "你將信箱交回驛站。\n");
    destruct(mbox);
  }
  
  return 0;
}

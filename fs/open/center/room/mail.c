// copy from Room: /open/wiz/post_office.c

inherit ROOM;

void create ()
{
  set ("short", "武威鑣局附設文書部");
  set ("long", @LONG
這是一間十分雜亂的房間，到處堆滿了各地往來的文書，包括各省
的通告。如果你想寫信給遠在他鄉的親友，可以來此地辦理各種文書業
務，由於武威鑣局信用可靠，所以不必擔心文書會遺失。
    前面豎著一塊木牌(sign)，上面似乎有字，你不妨靠近點瞧瞧。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/center/room/biau",
]));

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "牌子上寫道﹕

          各種業務請見說明書。

",
]));

  set("light_up", 1);

  setup();
}

int valid_leave(object me, string dir)
{
        object mbox;

        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "你將說明書仔細擺\放好。\n");
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
      write ("掌櫃的一看你踏進門來, 馬上哈腰遞給你一張說明書\n");
  }

  add_action ("do_home", "home");
  add_action ("do_goto", "goto");
}

int do_home(string arg)
{
  object mbox, me;

  me = this_player();
  if( mbox = me->query_temp("mbox_ob") ) {
    tell_object(me, "你將說明書交回驛站。\n");
    destruct(mbox);
  }
  
  return 0;
}

int do_goto (string arg)
{
  object mbox, me;

  me = this_player();
  if( mbox = me->query_temp("mbox_ob") ) {
    tell_object(me, "你將說明書交回驛站。\n");
    destruct(mbox);
  }
  
  return 0;
}

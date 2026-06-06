//Code by Hitler  1995.10.2
//More added by Fex ..

inherit ROOM;

object ob;
string *name=({"hitler","devils","norman","fary","datas","nsk","moi","boss","lys","stupid","oda"});
int number=11;

void create ()
{
  set ("short", "武者巫師討論室");
  set ("long", @LONG
這裡是武者製作巫師的討論室, 有冷氣、冰箱, 還有沙發等豪華家具,
尚有充足的光線及優雅的辦公桌, 提供巫師們最舒適的環境! 並且設置了
巫師專用的佈告欄, 讓巫師們能將問題留言於上, 共同討論。
辦公桌上有一支麥克風(mac),呵...剛買的..:>>
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "mac" : "這是一支可愛的麥克風, 你可以透過它來向目前
線上的武館巫師傳訊息..
用法: mac 你要說的話 ...
",
]));

  set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/wu/room/school1",
  "down" : "/open/wiz/hall1",
]));

  set("no_fight", 1);

  set("no_magic", 1);

  set("no_clean_up", 0);

  set("valid_startroom", 1);


  setup();
        call_other("/obj/board/fexboard","???");
}

void init()
{
add_action("mac","mac");
}

int mac(string str)
{
int i,flag=0;

if(!str)
  {
   notify_fail("你總要說些話啊!!, 不然其他wiz 怎麼能聽得到呢?\n");
   flag=0;
   return 0;
  }
for(i=0;i<number;i++)
  {
    if(ob=find_player(name[i]))
    if(ob!=this_player())
    {
    tell_object(ob,"[武者製作] "+this_player()->query("id")+" 說: "+str+"\n");
    flag++;
    }
  }
  if(flag!=0)
  {
  write("你告訴全部的武者巫師："+str+"\n");
  }
  else
  {
  write("目前沒有其他武者巫師在線上, 所以沒人聽到你說的話。\n");
  }
  say(this_player()->query("name")+"("+this_player()->query("id")+")"+" 對著麥克風嘰嘰咕咕地說了些話..\n");
  flag=0;
  return 1;
}

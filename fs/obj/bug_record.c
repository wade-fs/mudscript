// obj:/u/b/bss/bug_record
#include <ansi.h>
inherit ITEM;
inherit F_SAVE;
mapping *records;
private void get_title(string txt,mapping record);
void get_record_text(mapping mail, string str);
void receive_mail(mapping record);
string get_id(string name);
string get_status(int status);

void create()
{
  set_name(HIC"bug回報機"NOR, ({"bug record","record"}));
  set ("long", "
"HIY"
(1) 請用 post 來發表 bug 。
(2) list 可以列出所有的 bug ，如果是你發表的 bug 你可以看內容，和巫師回應。
(3) read 編號，可以看該篇文章。
"NOR);

  set("light_up", 1);
  set("no_fight", 1);
  set("no_get", 1);
  set("no_sac", 1);
  set("no_put", 1);
  set("no_give", 1);
  set("no_steal", 1);
  set ("save_file", "/data/bug_record");
  setup();

}

string query_save_file() {
  return query ("save_file");
}
void init()
{
  add_action("do_record","post");
  add_action("do_check","list");
  add_action("do_study","read");
  add_action("do_del","del");
  add_action("do_chstatus","chstatus");
  add_action("do_rep","rep");

  restore();
}
int do_record()
{
        object user=this_player();
        mapping record;

        record = ([
                "from": this_player()->name(1) + "(" + this_player()->query("id") + ")",
                "title": "無題",
                "time": time(),
                "have_other_use?": "",
                "self_have_use?": "",
                "text": ""
        ]);
        write("請輸入bug主題(如xxxx的bug，直接按enter會放棄record):");
        input_to((: get_title :),0, record);
        return 1;
}
private void get_title(string txt,mapping record)
{
        printf("txt=%s\n",txt);
        if(!txt || txt=="")
        {
                printf("txt=%s\n",txt);
                write("你放棄了record!!\n");
                return ;
        }
        record["title"] = txt;
        write("回報內容:\n");
        this_player()->edit( (: get_record_text, record :) );
}
void get_record_text(mapping record, string str)
{
        record["text"] = str +"\n===================================================================";
        write("就你所知中，有其他的人知道或使用過這個bug嗎?(y/n)[n]:");
        input_to("confirm_copy", 0, record);
}

void confirm_copy(string yn, mapping record)
{
        if( yn[0]=='y' || yn[0]=='Y' )
                record["have_other_use?"]="yes";
        else
                record["have_other_use?"]="no";
        write ("請問你自己有用過這個bug嗎(y/n) ? [n]");
        input_to ("confirm_other", record);
}
void confirm_other(string yn, mapping record)
{
        if ( yn[0]=='y' || yn[0]=='Y' )
                record["self_have_use?"]="yes";
        else
                record["self_have_use?"]="no";
        write("多謝你回報bug,有發現其他的bug,歡迎隨時再來回報!!\n");
        CHANNEL_D->do_channel(this_object(),"sys",record["from"]+"回報 bug");
        receive_mail(record);
}
void receive_mail(mapping record)
{
        if( !pointerp(records) ) records = ({ record });
        else records += ({ record });
        save();
}
int do_check()
{
  int i;
  string str;
  object user=this_player();
//  if(!wizardp(user)) return 0;

  if( !pointerp(records) || !sizeof(records) ) {
    write("目前回報版沒有任何的文章。\n");
    return 1;
  }

  str = "回報版目前共有 " + sizeof(records) + " 篇文章﹕\n";
  str += "### 標題=========================================================\n";
  for(i=sizeof(records)-1; i>=0; i--) {
    str += sprintf("%3d %s\n["HIB"%8|s"NOR"]  回報人：%s, %s(%d 字)\n",
      i+1,
       records[i]["title"] ,
      (get_status(records[i]["status"])),
      (wizardp(user) ||  get_id(records[i]["from"] ) == user->query("id")) ? records[i]["from"] : "隱藏",
      ctime (records[i]["time"]),
      strlen (records[i]["text"])
    );
  }
    user->start_more(str);
    return 1;
}
int do_study(string arg)
{
        int num;
  object user=this_player();

        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("你要讀哪一篇文章﹖\n");

        if( !pointerp(records) || num < 1 || num > sizeof(records) )
                return notify_fail("沒有這個編號的文章。\n");

        num --;
        if(!wizardp(user) && get_id(records[num]["from"]) != user->query("id"))
          return notify_fail("對不起，你沒有權限看這篇文章。\n");

        printf("標題﹕%s\n回 報 人﹕%s\n",
                records[num]["title"], records[num]["from"]);
        printf("是否有其他人使用:%s\n",records[num]["have_other_use?"]);
        printf("個人是否使用:%s\n\n",records[num]["self_have_use?"]);
        printf("處理狀態:"HIB"%s"NOR"\n\n",get_status(records[num]["status"]));
        printf("內容:\n%s\n",records[num]["text"]);
        return 1;
}
int do_del(string arg)
{
        int num;
  object user=this_player();
  if(!wizardp(user)) return 0;

        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("你要刪除那一篇文章﹖\n");

        if( !pointerp(records) || num > sizeof(records) )
                return notify_fail("沒有這個編號的文章。\n");

        num --;

        records = records[0..num-1] + records[num+1..sizeof(records)-1];
        save();
        write("Ok.\n");

        return 1;
}
int do_chstatus(string arg)
{
        int num;
        int status;
        string *map_status;
  object user=this_player();
  map_status = ({
      "未處理","已處理","不用處理"
      });
  if(!wizardp(user)) return 0;

        if( !arg || !sscanf(arg, "%d %d", num,status) )
                return notify_fail("你要改變那一篇文章的狀態﹖\n");

        if( !pointerp(records) || num > sizeof(records) )
                return notify_fail("沒有這個編號的文章。\n");

        num --;
        switch(status)
        {
          case 1:
          case 2:
          case 3:
            records[num]["status"] = status;
            {
              object mbox;
              mapping mail = allocate_mapping(0);
              mbox = new(MAILBOX_OB);
                mail = ([
                    "from": user->name(1) + "(" + user->query("id") + ")",
                    "title": user->name(1)+"已經將["+
                      records[num]["title"]
                      +"]改變狀態。" ,
                    "to": get_id(records[num]["from"]),
                    "time": time(),
                    "text":  user->name(1)+"已經將["+records[num]["title"]+"]改為"+map_status[status]+"。\n"
                    ]);
                mbox->send_mail(get_id(records[num]["from"]),mail);

            }
            break;
          default:
            return notify_fail("只有 [0/1/2] 這三種狀態，分別為 [未處理/已處理/不用處理]。\n");
        }
        save();

        write("Ok.\n");

        return 1;
}
int do_rep(string arg)
{
        int num;
        string status;
  object user=this_player();

        if( !arg || !sscanf(arg, "%d %s", num,status) )
                return notify_fail("你要回應哪一篇文章？\n");

        if( !pointerp(records) || num > sizeof(records) )
                return notify_fail("沒有這個編號的文章。\n");

        num --;
        if(!wizardp(user) && get_id(records[num]["from"]) != user->query("id"))
          return notify_fail("對不起，你沒有權限回應這篇文章。\n");


        records[num]["text"] +=  "  "+ user->name(1) + "(" + user->query("id") + ") 回應："HIY+status+NOR"\n";
        save();
        write("Ok.\n");

        return 1;
}

string get_status(int status)
{
  string *str =( {RED"未處理","已處理",HIC"不用處理"});
  return str[status];
}
string get_id(string name)
{
  string id;
  sscanf(name,"%*s(%s)",id);
  return id;
}

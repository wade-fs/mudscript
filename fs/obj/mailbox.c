// mailbox.c
// Fix 顯示畫面, "from" 命令
// by wade@Fantasy.Spaace 87/7/31

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

mapping *mails;

void get_mail_text(mapping mail, string str);

void create()
{
	set_name("文書業務說明書", ({ "mailbox","box" }) );
	set("long",
		"你可以用以下指令來處理你的郵件﹕\n\n"
		"mail <某人>               寄信給別人。\n"
		"forward <信件編號> <某人> 將某封信轉寄給別人。\n"
		"from                      查看信箱中的信件。\n"
		"read <信件編號>           閱\讀一封信件。\n"
		"discard <信件編號>        丟棄一封信件。\n"
	);
	set("unit", "張");
	set("no_drop", 1);
	set("no_insert", 1);
	setup();
}

int set_owner(string id)
{
	set("owner_id", id);
	return restore();
}

void init()
{
	object ob;

	if( this_player() && environment()==this_player() ) {
		set_owner( getuid(this_player()) );
		this_player()->delete("new_mail");
		this_player()->set_temp("mbox_ob", this_object());
		add_action("do_mail", "mail");
		add_action("do_send", "send");
		add_action("do_sendg", "sendg");
		add_action("do_forward", "forward");
		add_action("do_from", "from");
		add_action("do_read", "read");
		add_action("do_discard", "discard");
        if(wizardp(this_player()))
          add_action("do_trans_file","trans_file");
	}
        if(this_player()->query_temp("mailspam"))
          this_player()->delete_temp("mailspam");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) ) return 0;

	return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{
	if( !pointerp(mails) ) mails = ({ mail });
	else mails += ({ mail });
	save();
}

void send_mail(string rcvr, mapping mail)
{
	object ppl, mbx, me=this_player();
       
	// Get the mailbox or make a new one if not found.
        me->add_temp("mailnum",1);//計算每人的寄信數
	ppl = find_player(rcvr);
	if( !mbx ) {
		mbx = new(MAILBOX_OB);
		mbx->set_owner(rcvr);
	}

	// Receive the mail and destruct the objects if receiver is off-line.
	mbx->receive_mail(mail);
	if(ppl){
		mbx = ppl->query_temp("mbox_ob");
                if(wizardp(ppl) && (ppl->query("env/invis")||ppl->query("env/隱身")))
                 printf("寄件人的英文ID:%s\n信寄出去了.\n",ppl->query("id"));
                else
		 write ("您請冰胖通知 " + rcvr + " 收信!\n");
		tell_object(ppl, GRN + "\n冰胖用千里傳音跟您說﹕有您的信﹗請去收信﹗\n\n" + NOR);
                if(me->query("combat_exp")<10000) ppl->add_temp("mailspam",1);//增加exp<10000的人寄給ppl的次數
	}
	else 
        {
         MAIL_D->send_mail(rcvr);
         me->add_temp("mail/"+rcvr,1);//計算exp<10000的寄給不在線上的人中每個人的次數
        }
    
       if(mbx)
        destruct(mbx);
}

int do_mail(string arg)
{
	mapping mail;
        object  me=this_player();
        object  resv;

	if( this_player()!=environment() ) return 0;

	if( !arg || arg=="" )
		return notify_fail("你要寄信給誰﹖\n");

        resv=find_player(arg);//exp小於1萬亂寄信的機制
        if(resv && file_size (sprintf ("/data/login/%s/%s.o", resv->query("id")[0..0], resv->query("id"))) <= 0) return notify_fail("抱歉，你要寄的對象年紀太小.\n");//防止收信人是新手未存檔導致可能被他人竊取問題
        if(!resv) resv=FINGER_D->acquire_login_ob(arg);
        if(!resv) return notify_fail("你要寄信給誰﹖\n");
        if(!wizardp(me) && me->query("combat_exp")<10000 && time()-me->query_temp("login_time")<1800) return 0;
        if(!wizardp(me) && me->query("combat_exp")<10000)
        {
         if(resv=find_player(arg))
         {
          if(resv->query_temp("mailspam")>1) return 0;
          if(me->query_temp("mail/"+arg)) me->delete_temp("mail/"+arg);
         }
         else
         {
          if(me->query_temp("mail/"+arg)>1) return 0;
         }
        }
        if(!wizardp(me))//限制每次login最多寄信數
        {
         if(me->query("combat_exp")<10000 && me->query_temp("mailnum")>4) return 0;
         if(me->query("combat_exp")>=10000 && me->query_temp("mailnum")>29) return 0;
        }

	mail = ([
		"from":	this_player()->name(1) + "(" + this_player()->query("id") + ")",
		"title": "無題",
		"to": arg,
		"time": time(),
		"text": ""
	]);
	write("信件標題﹕");
	input_to("get_mail_title", 0, mail);
	return 1;
}

int do_send(string arg)
{
	object	me=this_player();
	string	file, title;
	mapping mail;

	if( this_player()!=environment() ) return 0;
        if(!wizardp(me)) return 0;

	if ( !arg || arg=="" || sscanf (arg, "%s %s", file, title) != 2)
		return notify_fail("send <file> <title>\n");

	file = resolve_path(me->query("cwd"), file);
	if (file_size(file) < 0) {
	  write ("你給的檔名可能不存在, 也許\是您打錯了吧!\n");
	  return 1;
	}
	mail = ([
		"from":	me->name(1) + "(" + me->query("id") + ")",
		"title": title,
		"time": time(),
		"text": read_file(file),
	]);
	write("寄給誰? ");
	input_to("get_id", 0, mail);
	return 1;
}

int do_sendg(string arg)
{
	object	resv,me=this_player();
	string	file, title, group;
	string	*groups;
	int	i;
	mapping mail;

	if( this_player()!=environment() ) return 0;
        if(!wizardp(me)) return 0;

	if ( !arg || arg=="" ||
	     sscanf (arg, "%s %s %s", group, file, title) != 3)
		return notify_fail("sendg <group> <file> <title>  <-- 請用 groups 命令設定 groups 變數.\n");

	file = resolve_path(me->query("cwd"), file);
	if (file_size(file) < 0) {
	  write ("你給的檔名可能不存在, 也許\是您打錯了吧!\n");
	  return 1;
	}
	if (!groups=me->query("groups/"+group)) {
	  write ("查無此群組, 請用 groups 命令更改您的 groups 變數.\n");
	  return 1;
	}
	mail = ([
		"from":	me->name(1) + "(" + me->query("id") + ")",
		"title": title,
		"time": time(),
		"text": read_file(file),
	]);

	printf ("你要寄給下列人士: %O\n", groups);
	for (i=0; i<sizeof(groups); i++) {
          resv=find_player(groups[i]);
          if(!resv) resv=FINGER_D->acquire_login_ob(groups[i]);
          if(resv)
          {
           if(file_size (sprintf ("/data/login/%s/%s.o", groups[i][0..0], groups[i])) <= 0) write("抱歉，你要寄的對象年紀太小.\n");//防止收信人是新手未存檔導致可能被他人竊取問題
           else
           {
	    mail["to",groups[i]];
            send_mail(groups[i], mail);
           }
          }
          else
           printf("%s 不存在\n",groups[i]);
	}
	
	return 1;
}

void get_mail_title(string str, mapping mail)
{
	if( str!="" ) mail["title"] = str;
	write("信件內容﹕\n");
	this_player()->edit( (: get_mail_text, mail :) );
}

void get_mail_text(mapping mail, string str)
{
	mail["text"] = str;
	write("您自己要留一份備份嗎(y/n)﹖[n]");
	input_to("confirm_copy", 0, mail);
}

void confirm_copy(string yn, mapping mail)
{
        object  me=this_player();
	if( yn[0]=='y' || yn[0]=='Y' ) receive_mail(mail);
	send_mail(mail["to"], mail);
	write ("請問還有要寄給誰嗎(y/n) ? [n]");
	input_to ("confirm_other", 0, mail);
}

void get_id (string str, mapping mail)
{      
        object  resv,me=this_player();
        resv=find_player(str);
        if(!resv) resv=FINGER_D->acquire_login_ob(str);
	if(resv)
        {
         if(file_size (sprintf ("/data/login/%s/%s.o", resv->query("id")[0..0], resv->query("id"))) <= 0) write("抱歉，你要寄的對象年紀太小.\n");//防止收信人是新手未存檔導致可能被他人竊取問題
         else
         {
          mail["to"] = str;
          send_mail(str, mail);
         }
        }
        else
         write ("無此人\n");
	write ("請問還有要寄給誰嗎(y/n) ? [n]");
	input_to ("confirm_other", 0, mail);
}

void confirm_other(string yn, mapping mail)
{
        object  me=this_player();
        if ( (yn[0]=='y' || yn[0]=='Y') && !(!wizardp(me) && me->query("combat_exp")<10000) && me->query_temp("mailnum")<30 ) {
	  write ("請一次一個輸入名單, 結束請用句點 '.'  : ");
	  input_to("mail_other", 0, mail);
	}
}

void mail_other(string name, mapping mail)
{
        object resv,me=this_player();
        if(me->query_temp("mailnum")>29) name=".";
	if (name == ".")
	  write ("信寄出去了.\n");
	else {
          resv=find_player(name);
          if(!resv) resv=FINGER_D->acquire_login_ob(name);
          if(resv)
	  { 
            if(file_size (sprintf ("/data/login/%s/%s.o", resv->query("id")[0..0], resv->query("id"))) <= 0) write("抱歉，你要寄的對象年紀太小.\n");//防止收信人是新手未存檔導致可能被他人竊取問題
            else
            {
             mail["to"] = name;
	     send_mail(name, mail);
            }
          }
          else
            write ("無此人\n");
	  write ("請一次一個輸入名單, 結束請用句點 '.'  : ");
	  input_to("mail_other", 0, mail);
	}
}

int do_from()
{
  int i;

  if( !pointerp(mails) || !sizeof(mails) ) {
    write("你的信箱中目前沒有任何信件。\n");
    return 1;
  }

  write ("你的信箱中現在共有 " + sizeof(mails) + " 封信件﹕\n");
  write ("### 標題=========================================================\n");
  for(i=0; i<sizeof(mails); i++) {
    printf("%3d %s\n\t寄件人：%s, %s(%d 字)\n",
      i+1,
      mails[i]["title"],
      mails[i]["from"],
      ctime (mails[i]["time"]),
      strlen (mails[i]["text"])
    );
  }
    write("\n");
    return 1;
}

int do_read(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要讀哪一封信﹖\n");

	if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
		return notify_fail("沒有這個編號的信件。\n");

	num --;

    this_player()->start_more(sprintf("信件標題﹕%s\n寄 信 人﹕%s\n\n%s\n",
        mails[num]["title"], mails[num]["from"], mails[num]["text"] ));

	return 1;
}

int do_discard(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要丟棄哪一封信﹖\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("沒有這個編號的信件。\n");

	num --;

	mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
	save();
	write("Ok.\n");

	return 1;
}

int do_forward(string arg)
{
        object  me=this_player();
        object resv;
	string dest;
	int num;
	mapping m;

        if(!wizardp(me) && me->query("combat_exp")<10000) return 0;

	if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
		return notify_fail("你要將哪一封信轉寄給別人﹖\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("沒有這個編號的信件。\n");

        if(!wizardp(me) && me->query_temp("mailnum")>29) return 0;//限制每次login最多寄信數


        resv=find_player(dest);
        if(resv && file_size (sprintf ("/data/login/%s/%s.o", resv->query("id")[0..0], resv->query("id"))) <= 0) return notify_fail("抱歉，你要寄的對象年紀太小.\n");//防止收信人是新手未存檔導致可能被他人竊取問題
        if(!resv) resv=FINGER_D->acquire_login_ob(dest);
        if(!resv) return notify_fail("無此人﹖\n");

	num --;

	m = ([]);
	m["title"] = mails[num]["title"];
	m["text"] = mails[num]["text"];
	m["time"] = mails[num]["time"];
	m["from"] = mails[num]["from"] + "/轉寄自" + this_player()->query("name");
	m["to"] = dest;
	send_mail( dest, m );
	write("Ok.\n");

	return 1;
}

void owner_is_killed() { destruct(this_object()); }
int do_trans_file(string arg)
{
    int num;
    string file_name,out,temp;
    object me=this_player();

    if(!arg) 
      return notify_fail("指令格式:trans_file 信的篇數 檔名\n");
    if(sscanf(arg,"%d %s",num,file_name)!=2)
      return notify_fail("指令格式:trans_file 信的篇數 檔名\n");
    if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
      return notify_fail("沒有這個編號的信件。\n");
    num--;
    file_name= resolve_path(me->query("cwd"), file_name);
    if(file_size(file_name) >0)
      return notify_fail("檔案已經存在, 請另存一個新檔!!\n");
    out="";
    out=sprintf("信件標題﹕%s\n寄 信 人﹕%s\n\n%s\n",
        mails[num]["title"], mails[num]["from"], mails[num]["text"] );
    if(write_file(file_name,out))
      return notify_fail("第 "+sprintf("%d",num+1)+" 篇:"+mails[num]["title"]
                          +"寫入"+file_name+"成功\!!\n");
    else
      return notify_fail("無法寫入檔案!!\n");
}
    



   

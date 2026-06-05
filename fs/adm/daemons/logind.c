// 有改過, 能在輸入名字錯誤太多次之後自動斷線
// fixed by wade Thu Sep 28 1995
// fixed by wade 增加 okip, check passwd 警告 12/11/1995
// 增加 sleep 功能 by wade 87/8/11.

// 1999.11.16 by Server
// 加入呼叫 loginwaitd.c 的檢查
// destruct() -> void new_destruct(object ob);

//使用新的信件通知系統by bss
//主程式在/adm/daemons/cmaild.c裡

#include <net/socket.h>
#include <socket_err.h>
#include <ansi.h>
#include <command.h>
#include <limit.h>
#include <login.h>


#define LOCK "/include/lock.h"
#define RELOG_IP "/adm/daemons/relog_ip.c"

inherit F_DBASE;

int wizlocklevel=0;

string *banned_name = ({
  "幹", "妳", "我", "他", "她", "牠", "它",
  "菠蘿麵包", "冰判官", "巫師", "上帝", "天神", "天帝","拉姆","地皇",
});

// 名字不能含有下列字樣的某部份
string *banned_id = ({
  "fuck", "shit", "wizard", "god", "wiz","gy","corpse", "imm", "manager", "adm", "apr", "arch", "sex"
});
mapping gift = ([
  "str":"膂力",
  "cor":"膽識",
  "int":"悟性",
  "spi":"靈性",
  "cps":"定力",
  "per":"容貌",
  "con":"根骨",
  "kar":"福緣",
  ]);

mapping day2num =([
  "Mon"   : 1,
  "Tue"   : 2,
  "Wed"   : 3,
  "Thu"   : 4,
  "Fri"   : 5,
  "Sat"   : 6,
  "Sun"   : 7
]);

string *ok_ip = ({
"140.117.201.101",
"192.192.35.241",
"192.192.35.242",
"211.75.78.241",
"211.75.78.81", // sm2
});

mapping attrs=([
    "str"  :  "膂力",
    "cps"  :  "定性",
    "int"  :  "悟性",
    "cor"  :  "膽識",
    "con"  :  "根骨",
    "spi"  :  "靈性",
    "per"  :  "容貌",
    "kar"  :  "福緣",
]);

mapping nattr=([
    "str"  :  "cps",
    "cps"  :  "int",
    "int"  :  "cor",
    "cor"  :  "con",
    "con"  :  "spi",
    "spi"  :  "per",
    "per"  :  "kar",
]);

mapping blocks  = ([]);

// by konn 將正確的時間換算出來
int thistime, nowtime, player_day, player_week, day;
int nowhour;

void get_points (string points, object ob, object user, int tp, string attr, int i);
void get_id(string arg, object ob, int times);
void get_id(string arg, object ob);
void confirm_id(string yn, object ob);
object make_body(object ob);
varargs void enter_world(object ob, object user);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
void new_destruct(object ob);
void check_log(object ppl);
void get_ctrlc(string str, object ob, int count);
private void get_email(string email, object ob);

string str, my_ip, ip1, ip2, ip3, ip4, ipp1, ipp2, ipp3, ipp4;
void create()
{
  seteuid(getuid());
  set_temp("channel_id", "連線精靈");
  if( !mapp(blocks) ) blocks = ([]);
  if( !mapp(day2num) ) day2num = ([
  "Mon"   : 1,
  "Tue"   : 2,
  "Wed"   : 3,
  "Thu"   : 4,
  "Fri"   : 5,
  "Sat"   : 6,
  "Sun"   : 7
]);
}

// by konn
int query_time()
{
  return time();
}


// logon --> logonn
void logon (object ob)
{
  write("DEBUG: logind.c logon() called!\n");
  object *usr;
  string str;
  int i, t, wiz_cnt, ppl_cnt, login_cnt, *save_keys,time;

  // by ACKY
  if( mapp(blocks) && blocks[query_ip_number(ob)] > time() ) {
    write("請勿連續嘗試﹐請您稍後再連線。\n");
    new_destruct(ob);
    return;
  }

  // by konn
  if (CBIP_D->check_ip(ob)) {
    write("對不起﹐此 IP 目前已被停用。\n");
    new_destruct (ob);
    return;
  }

  time=0;
  if (time = RELOG_IP->check_ip(ob)) {
    write("對不起﹐此 IP 目前已被停用。\n");
    printf("你要等到 %s 才可以連線。\n",ctime(time));
    destruct(ob);
    return ;
  }

  cat(WELCOME, 1);
  UPTIME_CMD->main();

  if (file_size ("/include/lock.h") > 0) {
    if (sscanf (read_file (LOCK), "%d", wizlocklevel) != 1) {
      log_file ("/log", LOCK+ " format error!\n");
    }
  }

  usr = users();
  wiz_cnt = 0;
  ppl_cnt = 0;
  login_cnt = 0;
  for(i=0; i<sizeof(usr); i++) {
    if( !environment(usr[i]) ) {
      if (interactive(usr[i])) login_cnt++;
      else destruct(usr[i]);
    }
    else if( wizardp(usr[i]) ) wiz_cnt++;
    else if( !usr[i]->query_temp("netdead") ) ppl_cnt++;
  }
  if(file_size("/data/player") >0){
    string data_content = read_file("data/player", 1, 1);
    if (data_content != "") {
      sscanf(data_content, "%d %d %d", player_week, player_day, day);
    }
    printf("今日上線人次: " + HIG + "%d" + NOR + ", 本週上線人次: " + HIY + "%d" + NOR + " 。\n", player_day, player_week );
  }
  // konn..
  nowtime = (time() + 28800) % 86400;
  if( nowtime > 28800 ) {
    printf ("此時段人數上限為 "+HIM+MAX_USERS+NOR + " 人, 線上共有 " + HIC + "%d" + NOR + " 位玩家, 以及 " + HIR + "%d" + NOR + " 位使用者嘗試連線中。\n",
    ppl_cnt, login_cnt );
  }
  else {
    printf("此時段人數上限為 "+HIM+MAX_USERS_2+NOR + " 人, 線上共有 " + HIC + "%d" + NOR + " 位玩家, 以及 " + HIR + "%d" + NOR + " 位使用者嘗試連線中。\n",
    ppl_cnt, login_cnt );
  }

  CHANNEL_D->do_channel( this_object(), "sys:login", sprintf("(%s) IP:%-15s 嘗試連線中。",
  ctime(time()),query_ip_number()) );

  printf( HIY + "您正以位址 %s 連線中, 歡迎來到狂想空間。\n" + NOR, query_ip_number() );
  write("請輸入您的英文名字或以(guest)帳號參觀: ");
  input_to( (: get_id :), 0, ob, 1 );
}

// by konn  取得ctrl key 的值
// 為了要輸入太多次之後能夠斷線, 增加了一個參數 times
// void get_id(string arg, object ob)
// 其他地方的參數修改不予以一一列出
// fixed by wade Thu Sep 28 1995
void get_id(string arg, object ob, int times)
{
  if (!arg || !stringp(arg) || arg == "") {
    if (ob) new_destruct(ob);
    return;
  }
  int all_players=0;
  int all_wizs=0;
  int i;
  int max_users;
  int *save_keys, sock, sock2, sock3, sock4, sock5, ok = 0;
  object *all_user;
  object  ppl,user;
  object  *user_a;

  if (stringp(arg)) arg = lower_case(arg);
  if( !check_legal_id(arg)) {
    // 底下這個 if 是為了要輸入太多次之後能夠斷線
    // fixed by wade Thu Sep 28 1995
    if (times >= 3) {
      write ("對不起, 您輸入太多次了。\n");
      new_destruct (ob);
      return;
    }
    write("您的英文名字﹕");
    input_to("get_id", 0, ob, times+1);
    return;
  }

  all_user = users();
  all_wizs = 0;
  all_players = 0;
  for(i=0; i<sizeof(all_user); i++) {
    if( !environment(all_user[i]) ) {
      if( !interactive(all_user[i]) )
  destruct(all_user[i]);
    }
    else if( wizardp(all_user[i]) ) all_wizs++;
    else if( !all_user[i]->query_temp("netdead") ) all_players++;
  }

  map_delete( blocks, query_ip_number(ob) );
  ob->set( "id", arg );

  nowtime = (time() + 28800) % 86400;
  if( nowtime > 28800 )
    max_users = MAX_USERS;
  else
    max_users = MAX_USERS_2;

  if (all_players >= max_users) {

    if( ""+SECURITY_D->get_status(arg)=="(player)" || arg == "guest")
    {
    write("對不起﹐"+MUD_NAME+"的玩家已經太多了﹐請待會再來。\n");
    new_destruct(ob);
    return;
    }
    if (all_wizs >= 7 &&
    ""+SECURITY_D->get_status(arg)!="(admin)" &&
    ""+SECURITY_D->get_status(arg)!="(manager)" &&
    ""+SECURITY_D->get_status(arg)!="(guest)" &&
    ""+SECURITY_D->get_status(arg)!="(arch)")
    {
      write("對不起﹐"+MUD_NAME+"的玩家已經太多了﹐請待會再來。\n");
      new_destruct(ob);
      return;
    }
  }

  if( (string)ob->set("id", arg) != arg ) {
    write("Failed setting user name.\n");
    new_destruct(ob);
    return;
  }

  if( arg=="guest" ) {
    if ( wizlocklevel > 0) {
  write (HIY+WIZ_LOCK+NOR);
  destruct(ob);
  return;
    }
    
    
    if (user=find_player("guest"))
      if (interactive(user)) {
  write( "對不起, 已有一位 guest 在裡面混了。\n" );
  new_destruct (ob);
  return;
      }
      else new_destruct (user);
    // If guest, let them create the character.
    ob->set("name", "神祕過路客");
    ob->set("password", crypt("guest",0) );
    ob->set("body", USER_OB);
    user = make_body(ob);
    user->set("food", user->max_food_capacity());
    user->set("water", user->max_water_capacity());
    user->set("gender", "男性");
    write("\n歡迎參觀狂想空間。\n");
    log_file( "USAGE", sprintf("%s(%s) logined from %s (%s)\n", user->query("name"),user->query("id"),query_ip_number(ob), ctime(time())));//guest紀錄  建議搭配適當檢查連續嚐試重複登入guest的自動檢查封鎖(如firewall),否則不建議log guest紀錄
    enter_world(ob, user);
    return;
  }
  else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
    if( ob->restore() ) {
  // by konn
  // mark by bss,現在直接限ip,所以工作站不用擋

  // 防止惡人變身作弊 by ACKY
  user_a = users();
  for( i=0; i<sizeof(user_a); i++ )
    if( arg == user_a[i]->query("old_id") ) {
      write( "對不起, 禁止 multi login。\n");
      new_destruct(ob);
      return;
    }
  // add by whatup for ftp 的功能
  if (BANMULTI_D->ban_multi(ob)) {
    printf ("對不起，目前此 IP 允許\之最大上線人數已額滿。\n");
    new_destruct(ob);
    return;
  }  
    

    write(arg+" 已經註冊過了, 請輸入密碼﹕");
    input_to("get_passwd", 1, ob);

    return;
    }
    else {
      write("您的人物檔案出了一些問題﹐請利用 guest 進入通知巫師處理。\n");
      new_destruct(ob);
      return;
    }
  }
  else {
      if (wiz_level (ob) < wizlocklevel) {
  write (HIR+WIZ_LOCK+NOR);
  new_destruct(ob);
      }
    for (i=0; i<sizeof(banned_id); i++) {
      if (strsrch(arg, banned_id[i]) == 0) {
  write("對不起﹐名字不能由 "+banned_id[i]+" 當開頭。\n");
  new_destruct (ob);
  return;
      }
    }
  }

  if (BANMULTI_D->ban_multi(ob) >= MAX_MULTI_UNUSUAL) {
    printf ("對不起，目前此 IP 允許\之最大上線人數已額滿。\n");
    new_destruct(ob);
    return;
  }
  write("使用 " + (string)ob->query("id") + " 這個名字將會創造一個新的人物﹐您確定嗎(y/n)﹖");
  input_to("confirm_id", 0, ob);
}

int check_passwd (string passwd)
{
  int   i, p, n;
  if ((n = strlen (passwd)) < 5) return 0;

  while (!(passwd[i] <= 'Z' && passwd[i] >= 'A' ||
     passwd[i] <= 'z' && passwd[i] >= 'a' ))
  {
    i++;
  }

  if (i < n) p = 1;
  if (p) {
    while (!(passwd[i] < 'A' ||
       passwd[i] > 'Z' && passwd[i] < 'a' ||
       passwd[i] > 'z' ))
    {
      i++;
    }
    if (i < n) p = 2;
  }

  return p == 2;
}


void get_passwd(string pass, object ob)
{
  string my_pass, id, fn;
  object user, officer;

  write("\n");
  my_pass = ob->query("password");
  if( crypt(pass, my_pass) != my_pass ) {
    write("密碼錯誤﹗\n");
    new_destruct(ob);
    return;
  }

  if (!check_passwd (pass)) {
    write ("您的密碼過於簡單, 請進入後更換密碼,\n"
     "至少含有普通英文非非英文字母各一個.\n");
  }

  // Check if we are already playing.
  id = ob->query("id");
  if (user=find_body(ob->query("id"))) {
      // by konn
      // mark by bss,現在沒有流量限制了,先mark
      if( !wizardp(user) ) {
        if( time() - user->query("net_count/date") > 86400 ) {
    user->set("net_count/unit", 0);
    user->set("net_count/count", 0);
    user->set("net_count/date", time());
        }
        // by ACKY
        else if( user->query("net_count/count") > MAX_KB ) {
    write( "\n您的網路流量已經用完。\n\n" );
    write( "距離下回補滿時間: "+CHINESE_D->chinese_period( 86400-(time()-user->query("net_count/date")))+"。\n" );
    new_destruct(user);
    return ;
        }

      }
    if (environment(user)) {
      if (user->query_temp("netdead")) {
        reconnect (ob, user);
        if (user->query("break_away")&& (officer=find_living("pkla officer")))
          officer->break_away(user);
         return;
      }
      write("您要將另一個連線中的相同人物趕出去﹐取而代之嗎﹖(y/n)");
      input_to("confirm_relogin", 0, ob, user);
      return;
    }
    new_destruct(user);
  }

  if( objectp(user = make_body(ob)) ) {
    if( user->restore() ) {
      // by konn
      if( !wizardp(user) ) {
        if( time() - user->query("net_count/date") > 86400 ) {
          user->set("net_count/unit", 0);
          user->set("net_count/count", 0);
          user->set("net_count/date", time());
        }
        //by ACKY
        else if( user->query("net_count/count") > MAX_KB ) {
          write( "\n您的網路流量已經用完。\n\n" );
          write( "距離下回補滿時間: "+CHINESE_D->chinese_period( 86400-(time()-user->query("net_count/date")))+"。\n" );
          destruct(user);
          new_destruct(ob);
          return ;
        }
      }
      log_file( "USAGE", sprintf("%s(%s) logined from %s (%s)\n",
      user->query("name"), id,
      query_ip_number(ob), ctime(time()) ) );
      enter_world(ob, user);
      if (!user) return ;
      user->set_temp("apply/armor",1);
      return;
    }

    fn = sprintf ("user/%c/%s.o", id[0], id);
    printf ("資料檔遺失....系統自動從備份檔中取回....請重新連線...\n");
    cp (DATA_DIR+"backup/"+fn, DATA_DIR+fn);

    destruct(ob);
    destruct(user);
    return;
  }
  write("請您重新創造這個人物。\n");
  confirm_id("y", ob);
}

void confirm_relogin(string yn, object ob, object user, int times)
{
  object old_link;

  if (times >= 3) {
    write ("對不起, 您輸入太多次了。\n");
    new_destruct (ob);
    return;
  }
  if( yn=="" ) {
    write("您要將另一個連線中的相同人物趕出去﹐取而代之嗎﹖(y/n)");
    input_to("confirm_relogin", 0, ob, user, times+1);
    return;
  }

  if( yn[0]!='y' && yn[0]!='Y' ) {
    write("好吧﹐歡迎下次再來。\n");
    new_destruct(ob);
    return;
  } else {
    tell_object(user, "有人從別處( " + query_ip_number(ob)
      + " )連線取代你所控制的人物。\n");
    log_file( "USAGE", sprintf("%s(%s) replaced by %s (%s)\n", user->query("name"),user->query("id"),query_ip_number(ob), ctime(time()) ) );
  }

  // Kick out tho old player.
  old_link = user->query_temp("link_ob");
  if( old_link ) {
    exec(old_link, user);
    new_destruct(old_link);
  }

  reconnect(ob, user);
}

void confirm_id(string yn, object ob)
{
  if( yn=="" ) {
    write("使用這個名字將會創造一個新的人物﹐您確定嗎(y/n)﹖");
    input_to("confirm_id", 0, ob);
    return;
  }

  if( yn[0]!='y' && yn[0]!='Y' ) {
    write("好吧﹐那麼請重新輸入您的英文名字﹕");
    input_to("get_id", 0, ob, 1);
    return;
  }

  write( @TEXT

請您想一個有氣質﹐有個性﹐又不會太奇怪的中文名字﹐特別要提醒您
的是﹐本 mud 是一個以古中國與東方為背景的世界 ﹐請不要取一些不
雅或是非中文的名字的名字﹐這個名字將代表你的人物﹐而且往後更改
將要付出代價﹐請務必慎重。
  ^^^^^^^^^^
(除了名字之外﹐本 mud 有許多取綽號、別稱的設計﹐所以鄭重建議您
 取一個比較像名字的中文名字。)

TEXT
  );
  write("您的中文名字﹕");
  input_to("get_name", 0, ob, 1);
}

void get_name(string arg, object ob, int times)
{
    // 底下這個 if 是為了要輸入太多次之後能夠斷線
    // fixed by wade Thu Sep 28 1995
    if (times >= 3) {
      write ("對不起, 您輸入太多次了。\n");
      new_destruct (ob);
      return;
    }
  if( !check_legal_name(arg) ) {
    write("您的中文名字﹕");
    input_to("get_name", 0, ob, times+1);
    return;
  }

  // printf("%O\n", ob);
  ob->set("name", arg);
  write("請設定您的密碼﹕");
  input_to("new_password", 1, ob);
}

void new_password(string pass, object ob)
{
  write("\n");
  if(0)
  if( !check_passwd (pass) ) {
    write("密碼的必須大於五個字元及含有普通及特殊字元﹐\n請重設您的密碼﹕");
    input_to("new_password", 1, ob);
    return;
  }
  ob->set("password", crypt(pass,0) );
  write("請再輸入一次剛剛的密碼﹐以確認您沒記錯﹕");
  input_to("confirm_password", 1, ob);
}

void confirm_password(string pass, object ob)
{
  object  user;
  string old_pass;

  write("\n");
  old_pass = ob->query("password");
  if( crypt(pass, old_pass)!=old_pass ) {
    write("您兩次輸入的密碼並不一樣﹐請重新設定一次密碼﹕");
    input_to("new_password", 1, ob);
    return;
  }     write("為了您自身的權益，請務必輸入正確的電子郵件!!\n");
  write("您的電子郵件地址﹕");
  input_to((:get_email:), 0, ob);
}

private void get_email(string email, object ob)
{
  object user;
  ob->set("email", email);

  ob->set("body", USER_OB);
  if( !objectp(user = make_body(ob)) )
  {
    write("創建失敗，是不是有東西壞了？！");
    return;
  }
  write("您要扮演男性(m)的角色或女性(f)的角色﹖");
  input_to("get_gender", 0, ob, user);
}

void get_gender(string gender, object ob, object user)
{
  if( gender=="" ) {
    write("您要扮演男性(m)的角色或女性(f)的角色﹖");
    input_to("get_gender", 0, ob, user);
    return;
  }

  if( gender[0]=='m' || gender[0]=='M' )
    user->set("gender", "男性");
  else if( gender[0]=='f' || gender[0]=='F' )
    user->set("gender", "女性" );
  else {
    write("對不起﹐您只能選擇男性(m)或女性(f)的角色﹕");
    input_to("get_gender", 0, ob, user);
    return;
  }

  write ("目前共有 "+sizeof(attrs)+
   " 項天賦可供自己調整，每項平均 20 點。\n");
  write ("請問您希望的"+attrs["str"]+
   "是多少? 合法的值是 10-30, 目前剩下 160 : ");
  input_to ("get_points", 0, ob, user, 160, "str", 1);
}

//  JJCHEN
void get_points (string points, object ob, object user, int tp, string attr, int i)
{
  int  n;

  if (i<0) i = 0;
  if ( sscanf (points, "%d", n) != 1 || n<10 || n>30 || n>tp ) {
     write (sprintf ("請問您希望的%s是多少? 合法值是 10-30, 目前剩下 %3d。\n^M
目前剩 %d 項需要設定, 選完此項之後至少必須剩下 %d 點 : ",
     attrs[attr], tp, 7-i, 70-i*10));
    input_to ("get_points", 0, ob, user, tp, attr, i);
    return;
  }
  user->set(attr, n);

  if (attr == "per") {
    tp = tp-n;
    if (tp < 10 || tp > 30) {
      tp += n;
      write ("您還有某些天賦需要設定，但是所剩的值不合法，全部重新設定一次。\n");
      write ("請問您希望的"+attrs["str"]+"是多少? 合法的值是 10-30, 目前剩下 160 : ");
      input_to ("get_points", 0, ob, user, 160, "str", 1);
    }
    else {
      user->set("kar", tp);
      log_file( "USAGE",sprintf("%s(%s) created from %s (%s)\n",user->query("name"),user->query("id"),query_ip_number(ob), ctime(time())));
      user->set_temp ("create", 1);
      user->set("food", 300);
      user->set("water", 300);
      enter_world(ob, user);
    }
  }
  else {
    tp = tp-n;
    if (tp < 10) {
      write ("您還有某些天賦需要設定，但是所剩的值不合法，全部重新設定一次。\n");
      write ("請問您希望的"+attrs["str"]+"是多少? 合法的值是 10-30, 目前剩下 160 : ");
      input_to ("get_points", 0, ob, user, 160, "str", 1);
    }
    else {
      attr = nattr[attr];
    write (sprintf ("請問您希望的%s是多少? 合法值是 10-30, 目前剩下 %3d。\n^M
目前剩 %d 項需要設定, 選完此項之後至少必須剩下 %d 點 : ",
     attrs[attr], tp, 8-i, 70-i*10));
      input_to ("get_points", 0, ob, user, tp, attr, i+1);
    }
  }
}

object make_body(object ob)
{
  string err;
  object user;
  int n;

if(ob->query("body"))
  user = new(ob->query("body"));
else
{
  user=new("/obj/user.c");
}

  if(!user) {
    write("現在可能有人正在修改使用者物件的程式﹐無法進行複製。\n");
    write(err+"\n");
    return 0;
  }
  seteuid(ob->query("id"));
  export_uid(user);
  export_uid(ob);
  seteuid(getuid());
  user->set("id", ob->query("id"));
  user->set_name( ob->query("name"), ({ ob->query("id")}) );
  user->set("title", "普通百姓");
  user->set("birthday", time() );
  user->set("potential", 1000);
  user->set("max_standby",20);
  user->set("str", 10 + random(21));
  user->set("cps", 10 + random(21));
  user->set("int", 10 + random(21));
  user->set("cor", 10 + random(21));
  user->set("con", 10 + random(21));
  user->set("spi", 10 + random(21));
  user->set("per", 10 + random(21));
  user->set("kar", 10 + random(21));
  user->set("combat_exp",30);
// 將原本食物飲水剛進入時為 0 改成 Full by  anmy
  user->set("food", user->max_food_capacity() * 2);
  user->set("water", user->max_water_capacity() * 2);
return user;
}

void press_enter(string arg, object ob, object user)
{
  string  startroom;
  string  *tuned_ch;
  object cloth,carry_money;
  object *inb;
  int j;

  if( user->is_ghost() )
    startroom = DEATHROOM;
  else if (!stringp(startroom = user->query("startroom")))
    startroom = STARTROOM;

  if (user->query("robot")) startroom = ROBOT_CHECK;

  if(user->query("have_get_rest")) {
    startroom="/open/wiz/guilty_room";
    user->set("startroom","/open/wiz/guilty_room");
  }

  if (user->query("jail_time")) {
    if (wiz_level(user) < 5 &&
        ((int)user->query("jail_time")>(int)user->query("mud_age")))
    {
      startroom = "/open/wiz/jail.c";
      user->set("startroom","/open/wiz/jail.c");
    }
    else user->delete("jail_time");
  }

  if (!user->query("max_standby")) user->set("max_standby",20);
  user->set("max_standby",user->query("t_standby")+20);

  if (!catch(load_object(startroom)))
    user->move(startroom);
  else if (!catch(load_object(STARTROOM))) {
    user->move(STARTROOM);
    startroom = STARTROOM;
    user->set("startroom", STARTROOM);
  }
  else user->move(VOID_OB);

  ENTER_D->check_okip(user);
  if (wiz_level(user) < 5 && startroom && user) {
    tell_room (startroom, user->query("name") + "連線進入這個世界。\n",
               ({user}));
  }

  // 增加對 meq and godeq 的 mark by swy
  inb = all_inventory(user);
  for (j=0; j<sizeof(inb); j++) {
    if (inb[j]->query("id") == "mdragon-eq" ||
        inb[j]->query("id") == "god-eq" ||
        inb[j]->query("id") == "fire-turtle shield")
    {
      inb[j]->set("boss",user->query("id"));
    }
  }

  //把不是惡人的身上的lucky neck 消掉 by bss
  inb = all_inventory (user);
  for (j=0; j<sizeof(inb); j++)
  if (inb[j]->query("id") == "lucky-neck" && user->query("class")!="bandit") {
    write (inb[j]->query ("name") +
           "是惡人專用的，你不是惡人不能用，系統幫你刪除!!\n");
    destruct(inb[j]);
  }

  // acky
  if( !CLAN_D->have_clan( user->query("clan/id") ) ) {
    write("你的幫派已解散了，放你自由吧。\n");
    user->delete("clan");
  }

  if (wiz_level(user) < 6) {
    tell_room (startroom, user->query("name") + "連線進入這個世界。\n",
               ({user}));
  }

  if (user->query("new_mail")) {
    write (HIY +"\n\n有您的情書﹗去看看吧﹗\n\n" + NOR);
    user->set("new_mail", 0);
  }

  if (day==6 && day2num[ctime(time())[0..2]]==7)
    player_week = 0;

  if (day != day2num[ctime(time())[0..2]]) {
    player_day = 0;
    day = day2num[ctime(time())[0..2]];
  }
  write_file ("/data/player",
              sprintf ("%d %d %d", player_week+1, player_day+1, day), 1);

//下面這段顯示誰進入的區段,麻煩請不要移去by bss
  if (wiz_level(user) < 6) {
    CHANNEL_D->do_channel (this_object(), "sys",
      sprintf ("%s(%s)由 %s 連線進入。",
               user->name(),user->query("id"), query_ip_number(user)));
  }

  string ip = query_ip_number(user);
  delete(ip);
  tuned_ch = user->query_temp("channels");
  user->delete("brief");

  // channel 改成系統預設
  if (wizardp(user)) {
    user->set_temp( "channels",
      ({ "dead","music","mud","chat","rumor","war","twiz",
         "shout","sys","wiz","ct","gt","wiz*","ct*","ut","ut*",
         "ht*","ht","cb","cb*","sex"}) );
//    cat(WIZ_MOTD,1);
  }
  else {
    user->set_temp("channels",
      ({ "music","mud","chat","rumor","war","mt","mt*",
         "shout","dead","ct","gt","ct*","gt*","ut","ut*",
         "ht","ht*","cb","cb*","sex"}) );
//    cat(MOTD,1);
  }

  if (CMAIL_D->check_mail(user)) {
    tell_object (user, BLINK+
                 HIY + "<<武威鏢局附設文書部有你的信喔,請趕快去看!!!!>>\n" + NOR);
    CMAIL_D->del_mail(user);
  }
  if(!user->query("first_login")){
    if (!wizardp(user) && !user->query("env/no_cloth")) {
      cloth = new("/obj/cloth");
      cloth->move(user);
      cloth->wear();
    }

    user->set("first_login",time());
    int bday = user->query("birthday");
    if (!bday) bday = time();
    tell_object(user,
      sprintf(HBRED+HIY + "請牢記住自己的生日時刻為「"+HIW+"%d"+HIY+"」,"+
        " 這關係到日後若角色被竊的認證問題!!\n" + NOR, bday));
  }
  if(user->query("id")=="guest"){
      user->set("food", user->max_food_capacity());
      user->set("water", user->max_water_capacity());
  }
  //cat(NEWS, 1);
  {
    object board = load_object("/obj/board/news_b.c");
    mixed data = board->query("notes");
    int k = 0;

      string str = HIR + "\t\t\t最新消息：\n" + NOR + "\n===================================================\n";
    for(int i = sizeof(data)-1 ; i  > -1 ; i--)
    {
      if(k++ > 4) break;
      str += sprintf("標題:%-30s"+NOR+"/%-10s\n%s\n===================================================\n"+NOR,
          data[i]["title"] ,data[i]["author"],data[i]["msg"]);
    }
    tell_object(user,str);
  }
}

varargs void enter_world(object ob, object user)
{
  object cloth, room, carry_money,master;
  object coup, officer;
  string s,ss;
  string *gift_key,cname;
  int  login_time, i;

  user->set_temp("link_ob", ob);
  ob->set_temp("body_ob", user);
  exec(user, ob);

  user->setup();
  if(!user->query("family/master_is_ppl"))
    if(user->query("family/master_id") && user->query("class")!="prayer" && user->query("family/family_name")!="丐幫" && user->query("family/family_name")!="魔刀門" && user->query("family/family_name")!="魔刀莫測" ) {
      master=find_player(user->query("family/master_id"));
      i=0;
      if(!master) {
	master = FINGER_D->acquire_login_ob(user->query("family/master_id"));
	if(master)
          i=1;
      }
      if(master) user->set("family/master_is_ppl",1);
      if(i) {
        i=0;
        destruct(master);
      }
      user->save();
    }
      if (wiz_level(user) < wizlocklevel) {
  write (HIY+WIZ_LOCK+NOR);
  destruct(ob);
  destruct(user);
  return;
      }
  user->set("last_from", query_ip_number(user));
//  if (wizardp(user)) write("目前權限﹕" + wizhood(user) + "\n");
  if( wizardp(user) )
    write("目前權限 -> " + to_chinese(wizhood(user)) + wizhood(user) +"\n");


//
//      Modify by ICE... add e-mail address..
//
//  modified by wade .. 配合 pk rules....
  officer = find_living("pkla officer");
  if( user->query("break_away") && officer )
      officer->break_away(user);
  if(userp(user)) {
    // for 冬眠(sleep) 命令。   by wade 87/8/11
     if(user->query("sleep") >= time()) {
  write ("你需冬眠到"+ ctime(user->query("sleep")) +"…\n");
  new_destruct(user);
      }
}

// 幫派wiz, 玩家總管才可以有幫派 by ACKY
  if(!user) return;
  if( !CLAN_D->have_clan( user->query("clan/id") ) )
    user->delete("clan");
  if( user->query("PKNAME")==HIC + "(小淫賊)" + NOR )
    user->set( "PKNAME", " " );
  if( user->query("title")==HIC + "(小淫賊)" + NOR || !user->query("title") )
    user->set( "title", user->query("PKNAME") );

  // In case of new player, we save them here right after setup
  // compeleted.
  if (user) user->save();
//  if (ob) ob->save();

 if(!wizardp(user) && !user->query("env/no_cloth")){
  cloth = new("/obj/cloth.c");
  cloth->move(user);
  cloth->wear();
  }
  if(user->query("bss/wish")) user->delete("bss/wish");
//  carry_money = new("obj/money/gold");
//  carry_money->move(user);
  login_time = time();
  user->set_temp("login_time", login_time);

  UPDATE_D->check_user(user);
 //鑒於一堆ppl都把con往上加然後撐到reboot..而不使用quit..所以屬性不會降..
 //有違將屬性上限設為35之本意..所以在login也加入check........by CGY...
gift_key = keys(gift);
for(i=0; i<sizeof(gift); i++)
if( user->query(gift_key[i])>35 ) {
tell_object(user,"你的"+gift[gift_key[i]]+"過高﹐系統將它改為 35。\n");
    user->set(gift_key[i],35);
      }
  if (stringp (cname=user->query("couples/id")) && cname != "") {
    if (coup = find_player (cname)) {
      tell_object (user, HIR + "嘿嘿, 你的另一半在線上喔.\n" + NOR);
      tell_object (coup, HIR + "嘿嘿, 你的另一半來囉!\n" + NOR);
    }
    else if (file_size (sprintf ("/data/login/%s/%s.o", cname[0..0], cname)) <= 0) {
      user->delete ("couples");
      tell_object (user, HIR + "慘了, 你另一半自殺了, 就放你自由飛翔吧.\n" + NOR);
    }
    else
      tell_object (user, HIR + "啊..另一半沒上線, 放你孤單一個人在這兒.\n" + NOR);
  }
  check_log(user);
  write ("-- 請按 Enter 鍵繼續 --\n");
  input_to( "press_enter", 0, ob, user );
}

varargs void reconnect(object ob, object user, int silent)
{
  user->set_temp("link_ob", ob);
  ob->set_temp("body_ob", user);
  exec(user, ob);

  user->reconnect();
  user->set("last_from", query_ip_number(user));
  check_log(user);
  if( !silent ) {
    if( wiz_level(user) < 6 )
    tell_room(environment(user),
      user->query("name") + "重新連線回到這個世界。\n",
      ({user}));
  }
// Modify By Spirits. 10.02.1995
  if( wiz_level(user) < 6 )
    CHANNEL_D->do_channel( this_object(), "sys:login", sprintf("%s(%s)由 %s 重新連線進入。",
      user->query("name"), user->query("id"), user->query("last_from")) );
  UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
  int i;

  i = strlen(id);

  if( (strlen(id) < 3) || (strlen(id) > 10 ) ) {
    write("對不起﹐你的英文名字必須是 3 到 10 個英文字母。\n");
    return 0;
  }
  while(i--)
    if( id[i]<'a' || id[i]>'z' ) {
      write("對不起﹐你的英文名字只能用小寫英文字母。\n");
      return 0;
    }

  return 1;
}

int check_legal_name(string name)
{
  int i;

  i = strlen(name);

  if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
    write("對不起﹐你的中文名字必須是 1 到 6 個中文字。\n");
    return 0;
  }
  while(i--) {
    if( name[i]<=' ' ) {
      write("對不起﹐你的中文名字不能用控制字元。\n");
      return 0;
    }
    if( i%2==0 && !is_chinese(name[i..<0]) ) {
      write("對不起﹐請您用「中文」取名字。\n");
      return 0;
    }
  }
  if( member_array(name, banned_name)!=-1 ) {
    write("對不起﹐這種名字會造成其他人的困擾。\n");
    return 0;
  }

  return 1;
}

object find_body (string name)
{
  object ob, *body;

  if (objectp (ob= find_player(name)))
    return ob;
  body= children(USER_OB);
  for (int i=0; i<sizeof(body); i++)
    if (environment(body[i])&& getuid(body[i])==name)
      return body[i];
  return 0;
}

void new_destruct(object ob)
{
  int break_connect_flag;
  object break_connect_user; 

  if(!ob) return;
  if(!ob->query("id") || !query_ip_number(ob)) return ;
  // by ACKY
  blocks[query_ip_number(ob)] = time() + 10;
//add by bss, 將不斷重連的ip auto ban, wizlock時不會動作
  if(!wizlocklevel){
    break_connect_flag=0;
    if(find_player(ob->query("id"))){
      break_connect_user=find_player(ob->query("id"));
      if(userp(break_connect_user)) break_connect_flag=1;
    }
    if(!break_connect_flag) add(query_ip_number(ob),1);
  }
  if(query(query_ip_number(ob)) > 30 && !wizlocklevel){
    string ip = query_ip_number(ob);
    RELOG_IP->add_ip(sprintf("%s:%d",ip,(time()+86400*3)));
    delete(ip);
    CHANNEL_D->do_channel( this_object(), "sys:login", sprintf(HIG + "(%s) IP:%-15s 不當連續連線, 已被ban。" + NOR,
    ctime(time()),ip) );
  }
  destruct(ob);
}

string query_relog()
{
  string temp;
  int i;

  temp="";
  temp+=sprintf("%O\n",blocks);
  temp+=sprintf("%O\n",query_entire_dbase());
  return temp;
}

void check_log(object ppl)
{
 string ID,file;
 object diamond,stone;
 int num1,num2,num3,num4;
 num1 = 0;
 num2 = 0;
 num3 = 0;
 num4 = 0;
 if( !ppl ) return;
 if(!(ID=ppl->query("old_id")))
   ID = ppl->query("id");
 if( !stringp(ID) || ID == "" ) return;

  stone = present("original stone",ppl);

 if( !stringp(ID) || ID == "" ) return;
 if(ID!="guest") {
   file = sprintf("login/%s/%s", ID[0..0], ID);
   if(stone)
     if( stone->query("stone_id") )
       num4 = stone->query_amount();
   if(diamond)
     if( diamond->query("money_id") )
       num2 = diamond->query_amount();
    num1 = ppl->query("standby");
    num3 = ppl->query("clan/bank");

    log_file(""+file,sprintf("%s 登入時有 %d替身 %d鑽石 %d黃金(in clan) %d原石 於%s\n",ID,num1,num2,num3,num4,ctime(time())));
 }
 return;
}

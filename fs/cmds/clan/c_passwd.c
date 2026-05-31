inherit F_CLEAN_UP;

int main(object me, string str)
{
	if( !me->query("clan") )
		return notify_fail("你沒有幫派。\n");
        if( me->query("clan/rank") > 1)
            return notify_fail( "這個指令只有幫主可以用!!!\n" );
        if( me != this_player(1) )
                return 0;
        if( me->query("clan/passwd") == "0" )
        {
                write("請輸入新的密碼:");
                input_to("get_new_pass", 1, me);
                return 1;
        }
        write("為了安全起見, 請輸入你原來的密碼。\n");
        input_to("get_old_pass", 1, me);
        return 1;
}

void get_old_pass(string pass, object me)
{
        string old_pass;

        old_pass = me->query("clan/passwd");
        if( crypt(pass, old_pass) != old_pass ) {
                write("密碼錯誤。\n");
                return;
        }
        write("請輸入新的密碼:");
        input_to("get_new_pass", 1, me);
        return;
}

int check_passwd (string passwd)
{
  int   i, n, word,cnt;
  string txt;
  if ((n = strlen (passwd)) < 5) return 0;

  cnt=0;
  for(i=0;i<sizeof(passwd);i++)
  {
    txt=sprintf("%d",passwd[i]);
    sscanf(txt,"%d",word);
    if((word <= 122 && word >= 97) ||
       (word <= 90 && word >= 65))
      cnt++;
  }
  if(!cnt) return 0;
  else if(cnt==sizeof(passwd)-1) return 0;
  else return 1;

}

void get_new_pass(string pass, object me)
{
        if(!check_passwd (pass)) {
                write ("密碼必須至少含有一個普通英文字母跟一個非普通英文字母.\n");
                write("\n請再輸入一次新的密碼﹕");
                input_to("get_new_pass", 1, me );
        }
        write("\n請再輸入一次剛剛的密碼，以資確認﹕");
        input_to("confirm_new_pass", 1, me, crypt(pass,0));
}

private void confirm_new_pass(string pass, object ob, string new_pass)
{
        write("\n");
        if( crypt(pass, new_pass)!=new_pass ) {
                write("對不起﹐您輸入的密碼並不相同﹐繼續使用原來的密碼。\n");
                return;
        }
        if( !ob->set("clan/passwd", new_pass) ) {
                write("密碼變更失敗﹗\n");
                return;
        }
        ob->save();
        write("密碼變更成功\。\n");
}
int help(object me)
{
  write(@HELP
指令格式 : c_passwd
指令說明 :
         這個指令是用來更改幫派的密碼,在幫主宣佈滅幫時會用到!!
也是幫派的最後防線,所以身為幫主的人要記著幫派的密碼!!!
         系統基本上
         會要求你不能使用下列情形當密碼：
             1.  太短，目前設定是不能比五個字元短。
             2.  全部都是英文字，至少必須包括數字或特殊符號。
             3.  全部都是特殊符號，如全部都是數字。
HELP
    );
    return 1;
}

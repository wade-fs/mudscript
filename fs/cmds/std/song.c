// /cmds/std/song.c
//
// wade 在當兵前寫來自娛娛人的, 7/6/1996
// 
// 另一個重要的檔在 /obj/example/song.c
// 對寫歌的時候做了修正, 超過 100 首之後會自動把最不常唱的歌曲拿掉
// by wade 10/27/1996

#include <ansi.h>
 
int help (object);

int main(object me, string str)
{
  string        name, arg, *songs;
  object        song;

seteuid(getuid());
  if (!str) return help (me);

  if (sscanf (str, "%s %s", arg, name) != 2) arg = str;

  if (!arg) return help (me);

  if (catch (song = load_object ("/obj/example/song.c")))
    return notify_fail ("對不起, 點唱金榜壞了.\n");

  if (arg == "-e") {            // 編輯歌曲
    if (song->query_exist (name, me)) {
      write ("你要寫的歌曲別人已經寫了啊.\n");
      return 1;
    }
    me->set_temp ("song/歌名", name);
    write ("原唱者: ");
    input_to ("set_songer", 0, me);
  }
  else if (arg == "-d") {       // 清除歌曲
    song->delete_song (name, me);
    write ("刪除好了.\n");
    return 1;
  }
  else if (arg == "-c") {       // 點歌
    if(me->query_temp("song_count") > 5)
    {
       write("你已經點太多歌了.\n");
       return 1;
    }    
    if (song->play (name, me))
    {
      write ("開始演唱了.\n");
      me->add_temp("song_count",1);
    }
    else
      write ("沒有這首歌, 請選別首.\n");
    return 1;
  }
  else if (arg == "-l") {       // 列出所有歌曲
    if (!name) {        // -l 沒加歌名參數
      if (songs = song->query_top (3, 0))
        me->start_more (sprintf ("你要的歌曲是: %O\n", songs));
      else
        write ("對不起喔! 沒查到符合的.\n");
    }
    else {              // -l 有加歌名參數, 只列出該歌名
      if (song->query_songs (name))
        me->start_more (sprintf ("%O\n", song->query_songs (name)));
      else
        write ("沒有你要的這首曲子耶.\n");
      return 1;
    }
  }
  else if (arg == "-t") {       // 金曲龍虎榜
    if (songs = song->query_top (1, name))
      me->start_more (sprintf ("前十名的金排歌曲是: %O\n", songs));
    else
      write ("對不起喔! 現在沒有排行金曲獎.\n");
  }
  else if (arg == "-n") {       // 照歌名字數排
    if (songs = song->query_top (2, name))
      me->start_more (sprintf ("你要的歌曲是: %O\n", songs));
    else
      write ("對不起喔! 沒查到符合的.\n");
  }
  else if (arg == "-a") {       // 照原唱者字數排
    if (songs = song->query_top (3, name))
      me->start_more (sprintf ("你要的歌曲是: %O\n", songs));
    else
      write ("對不起喔! 沒查到符合的.\n");
  }
  else if (arg == "-s" && name) {       // 照歌名字數排
    if (songs = song->query_top (4, name))
      me->start_more (sprintf ("你要的歌曲是: %O\n", songs));
    else
      write ("對不起喔! 沒查到符合的.\n");
  }
  else return help (me);

  return 1;
}
 
// me 把歌曲 str 加入歌曲列表中. 要進入 edit() 中編寫
// 總歌曲數為 100, 超過的話, 會把使用次數低的踢掉.
void set_songer (string str, object me)
{
  if (!str) {
    me->delete_temp ("song");
    return;
  }
  me->set_temp ("song/原唱者", str);
  write ("底下開始輸入歌詞, 每句歌詞中間預設是停留兩秒, \n"
         "要更改停留時間, 請在兩句歌詞之間寫數字.\n");

  me->edit ( (: call_other,__FILE__, "set_song", me :) );
}

// 輸入完畢. 做適當的設定.
void set_song (object me, string str)
{
  string songer, name;
  object song;

  if (catch (song = load_object ("/obj/example/song.c"))) {
    me->delete_temp ("song");
    return;
  }

  if (song->song_number() >= 100)
    song->adjust();
  songer = me->query_temp ("song/原唱者");
  name   = me->query_temp ("song/歌名");
  song->add_song (name, me, songer, str);

  write ("你的歌曲 -- "+name+" 已經錄製好了.\n");
}

int help(object me)
{
  write(@HELP
命令語法: song -e 歌名          <-- 編輯一首曲子, 並且存檔
          song -d 歌名          <-- 只能砍掉自己寫的曲子
          song -c 歌名          <-- 點歌
          song -l [歌名]        <-- 列出目前的歌曲清單, 不加歌名則 == song -a
          song -t [N]           <-- 列出前Ｎ名的排行榜, 預設是前十名
          song -a [原唱者]      <-- 列出屬於該原唱者的歌, 不加的話照原唱者排
          song -s 字            <-- 搜尋含有該字的所有歌曲清單.
注意事項:
          song -n 4     <-- 只列出歌名長度是四個英文字或兩個中文字的
          song -n 4+    <-- 只列出歌名長度比四個英文字或兩個中文字長的
          song -n 4-    <-- 只列出歌名長度比四個英文字或兩個中文字短的
          song -n 4-10  <-- 只列出歌名長度在 4 到 10 個英文字之間的.
          使用 song -l 可以不加參數, 或者你要查詢詳細資料也可以.
          為了免去別人的打擾, 可以 set wait_edit
          使用 song -e 在寫歌曲的時候, 每句歌詞之前應該有 delay 項目
          delay 單位是秒, 不過, delay 可以省略, 省略的話, 系統預設是 3 秒
        底下列舉一個例子:
        2
        哥哥爸爸真偉大
        ....
        3
        只要我長大!
HELP
    );
    return 1;
}

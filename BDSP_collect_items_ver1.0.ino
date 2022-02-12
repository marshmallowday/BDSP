/*これはメニューバグ(BDSPver1.1.1,ver1.1.2,ver1.1.3で確認されているもの)によりアイテムを増殖させるプログラムです。ご利用は自身の責任のもとで行ってください。以下参考資料

Arduino　Leonardoの導入：https://pokemonit.com/micon-introduction/　または　https://tangential-star.hatenablog.jp/entry/20201107/1604761008

NintendoSwitchControlLibraryのインストール：https://github.com/lefmarna/NintendoSwitchControlLibrary

メニューバグver1.1.3のやり方：https://youtu.be/kvaZYAzIz1w  ver1.1.2：https://youtu.be/xHTyVEa0ZF8  ver1.1.1：https://youtu.be/5M09vQNJYXc

手順
①ボックス内のポケモンに「同じアイテム」を30体全員に持たせる
②バッグ内にあるアイテムの個数を数えて下のconst int already_collect_items=に代入する。
③レポートを書き（重要！）、メニューバグを発生させ、周りにNPCのいない場所で「ポケモン」→「ボックス」→Xボタン×5回→「ポケモン」→「ボックス」→Xボタン（道具が全て見えている状態）をしたのち、
ボックス左上のポケモンにカーソルを合わせてからSwitch本体またはスタンドにマイコンを挿す
④画面左上で「べんり」ではなく「つうじょう」で回収が行われていることを確認する（「べんり」になってしまったらマイコンを外してポケモンにカーソルを合わせて再び挿す。成功するまで行う）
⑤少なくとも一周は観察しておかしい挙動をしていないか確認する
⑥回収が終わると自動的に③の状態でストップするのでそこでマイコンを外す

*/

#include <NintendoSwitchControlLibrary.h>
#include <math.h>　


//アイテムを30体全員に持たせたあと、バッグにあるアイテムの個数を入力する

const int already_collect_items = 960 ;   //←960の部分に実際の数を入力してください。未入力だとnum_of_trials=0となり動作しません。

int x = already_collect_items/30 ;     

int num_of_trials = 32-x;   

void setup() {
  
  pushButton(Button::Y, 500, 10);
  
  //ここでSwitchがマイコンを認識するための時間稼ぎをしているが、「べんり」のまま回収を始めるとうまくいかないので「つうじょう」で回収が始まるまで何度かマイコンを挿し直す
  }

void loop() {
  for (int counter = 1; counter <= num_of_trials ; counter++) {
        
        collect_items();

        if(counter == num_of_trials){
           break;
          }
        }
  
  while(1){
    
    }
 }


void collect_items(){
  collect();   
  reset();
 }


void collect(){
  collect_from_left();   //第１行の回収と第2行への移行   ――――――――――↴
  collect_from_right();  //第2行の回収と第3行への移行    ――――――――――↩
  collect_from_left();   //第3行の回収と第4行への移行    ↪――――――――――↴
  collect_from_right();  //第5行の回収と第6行への移行    ――――――――――↩
  collect_from_left();   //第6行の回収                ↪――――――――――

  }

void reset(){
  
  //ここで１枚目（画面奥）のボックスに戻る
  pushButton(Button::B, 1500, 3);
  pushButton(Button::A, 1000);
  pushHat(Hat::DOWN, 1000);
  pushButton(Button::A, 2000);
  pushButton(Button::B, 1000);
  
  delay(2000);
  
  //ここで2枚目（画面手前）のボックスに再び移動する
  pushButton(Button::X, 1500, 5);
  pushButton(Button::A, 1000);
  pushButton(Button::R, 2500); //ゆっくり1500→2500
  pushButton(Button::X, 1500);

  }


void collect_from_left(){
  
  //奇数行の道具を左から回収していく
  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::RIGHT,300);

  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::RIGHT,300);

  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::RIGHT,300);

  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::RIGHT,300);

  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::RIGHT,300);

  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::DOWN,300);

  }

void collect_from_right(){
  
  //偶数行の道具を右から回収していく
  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::LEFT,300);

  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::LEFT,300);

  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::LEFT,300);

  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::LEFT,300);

  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::LEFT,300);

  pushButton(Button::A,300);
  pushHat(Hat::DOWN,300);
  pushButton(Button::A,500,3);
  pushHat(Hat::DOWN,300);
  
  }

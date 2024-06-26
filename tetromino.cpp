#include "tetromino.h"

// 사이즈와 shape 문자열을 통해 생성한다.
// 문자열은 size * size 길이의 문자열이 주어진다.

// 블록이 존재한다면 O를 통해 표시하고 아니라면 X를 통해 표시한다.
// 문자열은 개행 없이 일렬로 나열되어 주어진다.
// 예를 들어 T 미노의 모양과 생성은 다음과 같다.
// XOX
// OOO
// XXX
//
// Tetromino T("T", 3, "XOXOOOXXX")

// I 미노의 경우 다음과 같다.
// XXXX
// OOOO
// XXXX
// XXXX
//
// Tetromino I("I", 4, "XXXXOOOOXXXXXXXX")
//static Tetromino I, O, T, S, Z, J, L;
Tetromino::Tetromino(std::string name, int size, std::string shape)
{
    name_ = name;
    size_ = size;
    int idx = 0;
    for(int i = 0; i < size_; i++)
    {
        for(int j = 0; j < size_; j++)
        {
            if(shape[idx++] == 'O') shape_[j][i] = true;
            else shape_[j][i] = false;
        }
    }
    original_ = this;
}

Tetromino Tetromino::I("I", 4, "XXXXOOOOXXXXXXXX");
Tetromino Tetromino::O("O", 2, "OOOO");
Tetromino Tetromino::T("T", 3, "XOXOOOXXX");
Tetromino Tetromino::S("S", 3, "XOOOOXXXX");
Tetromino Tetromino::Z("Z", 3, "OOXXOOXXX");
Tetromino Tetromino::J("J", 3, "OXXOOOXXX");
Tetromino Tetromino::L("L", 3, "XXOOOOXXX");

// 시계 방향으로 회전한 모습의 테트로미노 객체를 반환한다.
Tetromino Tetromino::rotatedCW()
{
    // 변형되는 인덱스 값
    std::string temp;
    for(int i = 0; i < size(); i++)
    {
        for(int j = size() - 1; j >= 0; j--)
        {
            if(shape_[i][j]) temp += "O";
            else temp += "X";
        }
    }
    Tetromino rotate = Tetromino(name(), size(), temp);
    rotate.original_ = this->original_;
    return rotate;
}

// 반시계 방향으로 회전한 모습의 테트로미노 객체를 반환한다.
Tetromino Tetromino::rotatedCCW()
{
    std::string temp;
    for(int i = size() - 1; i >= 0; i--)
    {
        for(int j = 0; j < size(); j++)
        {
            if(shape_[i][j]) temp += "O";
            else temp += "X";
        }
    }
    Tetromino rotate = Tetromino(name(), size(), temp);
    rotate.original_ = this->original_;
    return rotate;
}

// 화면의 x, y 위치에 s 문자열로 테트로미노를 그린다
void Tetromino::drawAt(std::string s, int x, int y)
{
    for(int i = 0; i < size(); i++)
    {
        for(int j = 0; j < size(); j++)
        {
            if(shape_[i][j]) console::draw(i + x, j + y, BLOCK_STRING);
        }
    }
}
print("Welcome to tic-tac-toe")

# Introducing players
player1 = input("Enter Player 1 name: ")
print(f"Hello {player1}, you are X")

player2 = input("Enter Player 2 name: ")
print(f"Hello {player2}, you are O")

board = [[" ", " ", " "], [" ", " ", " "], [" ", " ", " "]]


acceptable_values = ["11", "12", "13", "21", "22", "23", "31", "32", "33"]


def display_board(board):
    print("    |    |    ")
    print(" " + board[0][0] + "  |" + " " + board[0][1] + "  |" + " " + board[0][2])
    print("--------------")
    print("    |    |    ")
    print(" " + board[1][0] + "  |" + " " + board[1][1] + "  |" + " " + board[1][2])
    print("--------------")
    print("    |    |    ")
    print(" " + board[2][0] + "  |" + " " + board[2][1] + "  |" + " " + board[2][2])


def get_input(player):
    print(f"{player} make your move:")
    position = "nopos"
    print(f"Available positions: {acceptable_values}")

    while position not in acceptable_values:
        position = input("Enter valid position: ")

        if position not in acceptable_values:
            print("Not a valid posiiton. TRY AGAIN! ")

    acceptable_values.remove(position)

    return position


def update_value(player):
    pos = get_input(player)
    mark = ""
    if player == player1:
        mark = "X"
    else:
        mark = "O"

    board[int(pos[0]) - 1][int(pos[1]) - 1] = mark
    display_board(board)


def check_winner(board, mark):
    return (
        (board[0][0] == mark and board[0][1] == mark and board[0][2] == mark)
        or (board[1][0] == mark and board[1][1] == mark and board[1][2] == mark)
        or (board[2][0] == mark and board[2][1] == mark and board[2][2] == mark)
        or (board[0][0] == mark and board[1][0] == mark and board[2][0] == mark)
        or (board[0][1] == mark and board[1][1] == mark and board[2][1] == mark)
        or (board[0][2] == mark and board[1][2] == mark and board[2][2] == mark)
        or (board[0][0] == mark and board[1][1] == mark and board[2][2] == mark)
        or (board[0][2] == mark and board[1][1] == mark and board[2][0] == mark)
    )


def game_logic():
    print("===============GAME BEGINS===============")
    while len(acceptable_values) != 0:
        update_value(player1)
        win_check = check_winner(board, "X")
        if win_check:
            print(f"{player1} has won!")
            break

        if len(acceptable_values) != 0:
            update_value(player2)
            win_check = check_winner(board, "O")
            if win_check:
                print(f"{player2} has won!")
                break
    else:
        print("GAME DRAWN!")


game_logic()

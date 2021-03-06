"""
Minimax Tic-Tac-Toe player.
"""
import sys
sys.path.append('../GameLogic')
import gamelogic as provided

name = "Minimax"

# SCORING VALUES
SCORES = {provided.PLAYERX: 1,
          provided.DRAW: 0,
          provided.PLAYERO: -1}


def move_mm(board, player, trials=None):
    """
    Make a move on the board.
    """
    score = board.check_win()

    if score is not None:
        return SCORES[score], (-1, -1)

    else:
        moves = board.get_empty_squares()
        compare = -2
        best_move = (-1, -1)
        best_score = -2
        for amove in moves:
            new_board = board.clone()
            new_board.move(amove[0], amove[1], player)
            result = move_mm(new_board, provided.switch_player(player))
            value = result[0] * SCORES[player]

            if value > 0:
                return result[0], amove
            else:
                if value > compare:
                    compare = value
                    best_score = result[0]
                    best_move = amove

        return best_score, best_move


def move(board, player, trials=None):
    """
    Wrapper for move_mm. This function is what is called by
    other modules.
    """
    return move_mm(board, player)[1]

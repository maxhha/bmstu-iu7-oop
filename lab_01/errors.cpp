#include "errors.hpp"

void handle_error(const err_t &code)
{
    switch (code)
    {
        case NO_MODEL:
            QMessageBox::critical(NULL, "Ошибка", "Нет загруженной модели.");
            break;
        case FILE_ERR:
            QMessageBox::critical(NULL, "Ошибка", "Не получилось открыть файл.");
            break;
        case ALLOC_ERR:
            QMessageBox::critical(NULL, "Ошибка", "Не получилось выделить память.");
            break;
        case READ_ERR:
            QMessageBox::critical(NULL, "Ошибка", "Не получилось прочитать файл.");
            break;
        case VERTECIESN_ERR:
            QMessageBox::critical(NULL, "Ошибка", "Некорретный размер количества точек.");
            break;
        case LINESN_ERR:
            QMessageBox::critical(NULL, "Ошибка", "Некорректный размер количества линий.");
            break;
        case LINEPTS_ERR:
            QMessageBox::critical(NULL, "Ошибка", "Некорректный индекс вершины в линии.");
            break;
        default:
            QMessageBox::critical(NULL, "Ошибка", "Неизвестная комманда.");
    }
}

#include "matrix.h"
#include "xl_tool/str_tool.h"
#ifdef DEBUG_TEST
#include <iostream>
#endif
namespace xl_math {
Matrix::Matrix(unsigned int row, unsigned int column): m_row(row), m_column(column){
    m_matrix.resize(m_row);
    for (unsigned int i = 0; i < m_row; i++) {
        m_matrix[i].resize(m_column);
    }
    //�������Ƿ��Ƿ���
    is_square = m_row == m_column ? true : false;
}
namespace {
std::string sep  = ";";
std::string sep2 = ",";
std::string sep_start = "[";
std::string sep_end   = "]";
}
Matrix::Matrix(const std::string& mat) {
    if (mat.empty() || std::string(1, mat[0]) != sep_start || &mat.back() != sep_end) {
        std::cout << mat << std::endl;
        return;
    }
    std::vector<std::string> str_list = xl_tool::StrTool::SplitString(mat.substr(1, mat.size()-2), sep);
    for (const std::string& str : str_list) {
        std::vector<std::string> list = xl_tool::StrTool::SplitString(str, sep2);
        std::vector<double> list_double = {};
        for (const std::string& s : list) {
            list_double.push_back(std::atof(s.data()));
        }
        m_matrix.push_back(list_double);
    }
    Update();
}

//Matrix::Matrix (const Matrix& source) {
//    m_row = source.m_row;
//    m_column = source.m_column;
//    is_square = source.is_square;
//    for (unsigned int j = 0; j < m_column; j++) {
//        for (unsigned int i = 0; i < m_row; i++) {
//            m_matrix[j][i] = source.m_matrix[j][i];
//        }
//    }
//}

//�������Ԫ���б�,��1��ʼ��
std::vector<double> Matrix::GetRowVector(const unsigned int row) {
    if (row > m_row || row < 1) {
        return {};
    }
    return m_matrix[row - 1];
}
//�������Ԫ���б�
std::vector<double> Matrix::GetColumnVector(const unsigned int column) {
    if (column > m_column || column < 1) {
        return {};
    }
    std::vector<double> column_vec(m_row);
    unsigned int count = 0;
    for (unsigned int i = 0; i < m_row; i++) {
        for (unsigned int j = 0; j < m_column; j++) {
            if (j == (column - 1)) {
                column_vec[count++] = m_matrix[i][j];
            }
        }
    }
    return column_vec;
}
bool Matrix::SetRowVector(const unsigned int row, const std::vector<double>& row_vector) {
    if (row > m_row || row < 1 || row_vector.size() != m_column) {
        throw "��������������ʧ�ܣ�����";
        return false;
    }
    m_matrix[row-1] = row_vector;
    return true;
}
bool Matrix::SetColumnVector(const unsigned int column, const std::vector<double>& column_vector) {
    if (column > m_column || column < 1 || column_vector.size() != m_row) {
        throw "��������������ʧ�ܣ�����";
        return false;
    }
    unsigned int count = 0;
    for (unsigned int i = 0; i < m_row; i++) {
        for (unsigned int j = 0; j < m_column; j++) {
            if (j == (column - 1)) {
                m_matrix[i][j] = column_vector[count++];
            }
        }
    }
    return true;
}

//ת��
Matrix Matrix::Transpose() {
    Matrix mat(m_column, m_row);
    for (unsigned int i = 0; i < m_row; i++) {
        for (unsigned int j = 0; j < m_column; j++) {
            mat.m_matrix[j][i] = m_matrix[i][j];
        }
    }
    return mat;
}

//����ʽ ��0��ʼ��
Matrix Matrix::Cofactor(const unsigned int r, const unsigned int c) {
    Matrix cofactor = Matrix(m_row - 1, m_column - 1);
    unsigned int m = 0, n = 0;
    for (unsigned int i = 0; i < m_row; i++) {
        if (i == (r - 1)) {
            continue;
        }
        for (unsigned int j = 0; j < m_column; j++) {
            if (j == (c - 1)) {
                continue;
            }
            cofactor.m_matrix[m][n++] = m_matrix[i][j];
        }
        m++, n = 0;
    }
    return cofactor;
}

//��������ʽ ��1��ʼ��
double Matrix::AlgebraicCofactor(const unsigned int r, const unsigned int c) {
    double k = ((r + c) % 2) ? (-1.0) : (1.0);
    return (Cofactor(r, c).Value() * k);
}

//�������
Matrix Matrix::Adjoint() {
    Matrix adjoint = Matrix(m_row, m_column);
    for (unsigned int i = 0; i < m_row; i++) {
        for (unsigned int j = 0; j < m_column; j++) {
            adjoint.m_matrix[i][j] = AlgebraicCofactor(i + 1, j + 1);
        }
    }
    return adjoint.Transpose();
}

//����������
Matrix Matrix::Inverse() {
    if (!is_square) {
        throw "�����Ƿ���������󣡣���";
        return {};
    }
    if (m_row > 3 || m_column > 3) {
        throw "����3���������δʵ�֣�����";
        return {};
    }
    Matrix A_adjoint = Adjoint();
    A_adjoint / Value();
    return A_adjoint;
}

//��������ʽ��ֵ
double Matrix::Value() {
    if (!is_square) {
        throw "�����Ƿ��󣬲��ܼ�������ʽ��ֵ������";
    }
    if (m_row == 1) {
        return m_matrix[0][0];
    }
    else if (m_row == 2) {
        return (m_matrix[0][0] * m_matrix[1][1] - m_matrix[1][0] * m_matrix[0][1]);
    }
    else if (m_row == 3) {
        return (m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2] +
                m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][0] +
                m_matrix[0][2] * m_matrix[1][0] * m_matrix[2][1] -
                m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1] -
                m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][2] -
                m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0]);
    }
    else {
        throw "�ݲ�֧�֣�����";
    }
//    double right = 1, left = 1, m = m_row - 1, n = 0;
//    for (unsigned int j = 0; j < m_column; j++) {
//         right *= m_matrix[j][n++];
//         left *= m_matrix[j][m--];
//    }
//    return (m_row % 2 == 1 ? -1 : 1) * (right - left);
}

//����[],��0��ʼ����
std::vector<double> Matrix::operator[] (unsigned int column) {
    return GetRowVector(column + 1);
}

//����=
bool Matrix::operator= (const Matrix& mat) {
    unsigned int row_size = mat.m_matrix[0].size(), column_size = mat.m_matrix.size();
    for (unsigned int i = 0; i < row_size; i++) {
        for (unsigned int j = 0; j < column_size; j++) {
            m_matrix[i][j] = mat.m_matrix[i][j];
        }
    }
    m_row = row_size, m_column = column_size;
    return true;
}

//����+
bool Matrix::operator+ (const Matrix& mat) {
    if (mat.m_row != m_row || mat.m_column != m_column) {
        throw "���󲻵ȼۣ����ܽ��мӷ����㣡����";
        return false;
    }
    for (unsigned int i = 0; i < m_row; i++) {
        for (unsigned int j = 0; j < m_column; j++) {
            m_matrix[i][j] += mat.m_matrix[i][j];
        }
    }
    return true;
}
bool Matrix::operator- (const Matrix& mat) {
    if (mat.m_row != m_row || mat.m_column != m_column) {
        throw "���󲻵ȼۣ����ܽ��м������㣡����";
        return false;
    }
    for (unsigned int i = 0; i < m_row; i++) {
        for (unsigned int j = 0; j < m_column; j++) {
            m_matrix[i][j] -= mat.m_matrix[i][j];
        }
    }
    return true;
}

//����* ����
bool Matrix::operator* (const double k) {
    for (unsigned int i = 0; i < m_row; i++) {
        for (unsigned int j = 0; j < m_column; j++) {
            m_matrix[i][j] *= k;
        }
    }
    return true;
}

//����/ ����
bool Matrix::operator/ (const double k) {
    if (k == 0) {
        return false;
    }
    for (unsigned int i = 0; i < m_row; i++) {
        for (unsigned int j = 0; j < m_column; j++) {
            m_matrix[i][j] /= k;
        }
    }
    return true;
}
//����^ ���
//������������ˣ�A * B��mat��
Matrix Matrix::operator^ (const Matrix& mat) {
    if (m_column != mat.m_row) {
        throw "�������в��Գƣ�������ˣ�����";
        return {};
    }
    Matrix square = Matrix(m_row, mat.m_column);
    for (unsigned int i = 0; i < square.m_row; i++) {
        for (unsigned int j = 0; j < square.m_column; j++) {
            for (unsigned int m = 0; m < mat.m_row; m++) {
                //ȡ����A��������     m_matrix[i][x]
                //ȡ����B�������� mat.m_matrix[x][j]
                square.m_matrix[i][j] += m_matrix[i][m] * mat.m_matrix[m][j];
            }
        }
    }
    return square;
}
#ifdef DEBUG_TEST
//�����ӡ����
void Matrix::Print(const std::string& name) {
    std::string space = "";
    if (!name.empty()) {
        std::cout << name << " =" << std::endl << std::endl;
        space = "    ";
    }

    unsigned int row = GetRowNumber(), column = GetColumnNumber();
    if (row < 1 || column < 1) {
        throw ("Matrix ������ȷ��������󣡣���");
    }
    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < column; j++) {
            std::cout << space << (m_matrix[i][j] >= 0 ? " " : "") << m_matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
#endif

void Matrix::Update() {
    m_column = m_matrix[0].size();
    m_row = m_matrix.size();
    //�������Ƿ��Ƿ���
    is_square = m_row == m_column ? true : false;
}
} //namespace xl_math

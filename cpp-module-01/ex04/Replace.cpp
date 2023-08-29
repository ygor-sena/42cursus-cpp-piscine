/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:19:13 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/29 14:44:52 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string removeString,
                 std::string insertString)
    : _filename(filename),
      _removeString(removeString),
      _insertString(insertString) {
  if (removeString.empty() || insertString.empty()) {
    std::cout << "Error: empty string" << std::endl;
    return;
  }

  std::ifstream inputFile(filename.c_str());
  if (!inputFile.is_open()) {
    std::cout << "Error: could not open file" << std::endl;
    return;
  }

  std::string newSufix = ".replace";
  std::ofstream outputFile(filename.append(newSufix).c_str());
  if (!outputFile.is_open()) {
    std::cout << "Error: could not open file" << std::endl;
    return;
  }

  std::string line;
  while (std::getline(inputFile, line)) {
    _replace(line, outputFile);
    if (!inputFile.eof())
      outputFile << std::endl;
  }

  inputFile.close();
  outputFile.close();
}

Replace::~Replace() {}

void Replace::_replace(std::string line, std::ofstream &outputFile) {
  size_t beginIndex = 0;
  size_t foundIndex = line.find(_removeString, beginIndex);

  while (foundIndex != std::string::npos) {
    outputFile << line.substr(beginIndex, foundIndex - beginIndex)
               << _insertString;
    beginIndex = foundIndex + _removeString.length();
    foundIndex = line.find(_removeString, beginIndex);
  }
  outputFile << line.substr(beginIndex, foundIndex - beginIndex);
  return;
}
